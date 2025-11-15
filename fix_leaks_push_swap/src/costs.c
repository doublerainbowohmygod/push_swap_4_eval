/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:05:01 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 16:55:17 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_stack *stack)
{
	int			size;
	t_stack		*current;

	size = 0;
	current = stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	set_cost_a(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->position;
		if (!(a->above_median))
			a->push_cost = len_a - (a->position);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->position;
		else
			a->push_cost += len_b - (a->target_node->position);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*current;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	current = stack;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	current = stack;
	while (current)
	{
		if (current->push_cost < cheapest_value)
		{
			cheapest_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
