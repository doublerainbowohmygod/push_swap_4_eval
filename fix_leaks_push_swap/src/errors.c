/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:20:38 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/25 14:01:15 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_and_exit_split(t_stack **stack_a, char **split)
{
	free_split(split);
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_and_exit(t_stack **stack_a)
{
	free_and_exit_split(stack_a, NULL);
}
