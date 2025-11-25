/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:51:42 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/25 14:01:23 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	handle_single_arg(t_stack **stack_a, char *arg)
{
	char	**split_args;

	if (!arg[0])
		return (1);
	split_args = ft_split(arg, ' ');
	if (!split_args || !split_args[0])
	{
		free_split(split_args);
		return (1);
	}
	parse_args(stack_a, split_args, split_args);
	free_split(split_args);
	return (0);
}

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_size(*a) < 6)
		sort_small(a, b);
	else
		sort_big(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	else if (ac == 2)
	{
		if (handle_single_arg(&stack_a, av[1]))
			return (1);
	}
	else
		parse_args(&stack_a, av + 1, NULL);
	assign_index(stack_a);
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
