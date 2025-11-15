/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:10:16 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 21:39:06 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_big(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		if (stack_size(*b) < 2)
			pb(a, b);
		else
		{
			init_nodes_a(*a, *b);
			push_a_to_b(a, b);
		}
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_current_position(*a);
	min_on_top(a);
}
