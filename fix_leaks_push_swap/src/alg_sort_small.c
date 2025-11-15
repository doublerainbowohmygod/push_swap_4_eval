/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:48:41 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 16:33:10 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_stack **s)
{
	if ((*s)->value > (*s)->next->value)
		sa(s);
	return ;
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		size;

	set_current_position(*a);
	min = find_min_value(*a);
	size = stack_size(*a);
	if (min->position < size / 2)
	{
		while ((*a) != min)
			ra(a);
	}
	else
	{
		while ((*a) != min)
			rra(a);
	}
	pb(a, b);
}

void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max_value(*a);
	if (max == *a)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int		size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else
	{
		while (size > 3)
		{
			push_min_to_b(a, b);
			size = stack_size(*a);
		}
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}
