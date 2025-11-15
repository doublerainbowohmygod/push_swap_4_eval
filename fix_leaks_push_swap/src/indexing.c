/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 08:23:12 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 21:38:57 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*find_min_no_index(t_stack *stack)
{
	t_stack	*min;
	t_stack	*current;

	current = stack;
	min = NULL;
	while (current)
	{
		if (current->index == -1 && (!min || current->value < min->value))
			min = current;
		current = current->next;
	}
	return (min);
}

void	assign_index(t_stack *stack)
{
	t_stack	*min;
	int		index;

	index = 0;
	min = find_min_no_index(stack);
	while (min)
	{
		min->index = index;
		index++;
		min = find_min_no_index(stack);
	}
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_in_b(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_in_a(a, b);
}
