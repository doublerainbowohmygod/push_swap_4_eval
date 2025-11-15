/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:02:01 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 13:21:02 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rrotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	last = *stack;
	while (last->next->next)
		last = last->next;
	*stack = last->next;
	last->next = NULL;
	(*stack)->next = head;
}

void	rra(t_stack **a)
{
	rrotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	rrotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	ft_putstr_fd("rrr\n", 1);
}
