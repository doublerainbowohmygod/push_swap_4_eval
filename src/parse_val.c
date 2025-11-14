/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:48:06 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 14:47:36 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	not_valid_number(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

static int	has_duplicates(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*i;

	i = stack;
	while (i && i->next)
	{
		if (i->value > i->next->value)
			return (0);
		i = i-> next;
	}
	return (1);
}

void	parse_args(t_stack **stack_a, char **av)
{
	long	num;
	int		i;

	i = 0;
	while (av[i])
	{
		if (not_valid_number(av[i]))
		{
			free_and_exit(stack_a);
		}
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_and_exit(stack_a);
		}
		if (has_duplicates(*stack_a, (int)num))
		{
			free_and_exit(stack_a);
		}
		append_node(stack_a, (int)num);
		i++;
	}
}
