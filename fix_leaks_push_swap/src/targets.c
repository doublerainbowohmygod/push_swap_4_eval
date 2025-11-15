/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:06:07 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 16:06:04 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*find_min_index(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

static t_stack	*find_max_index(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	set_target_in_b(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->index < a->index
				&& current_b->index > best_match_index)
			{
				best_match_index = current_b->index;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max_index(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_target_in_a(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->index > b->index
				&& current_a->index < best_match_index)
			{
				best_match_index = current_a->index;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min_index(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
