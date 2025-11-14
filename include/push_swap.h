/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:56:20 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 21:39:01 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					position;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack;	

 void	sort_three(t_stack **a);
 void	sort_small(t_stack **a, t_stack **b);
 void	sort_big(t_stack **a, t_stack **b);
 void	push_a_to_b(t_stack **a, t_stack **b);
 void	push_b_to_a(t_stack **a, t_stack **b);
 int	stack_size(t_stack *stack);
 void	set_cost_a(t_stack *a, t_stack *b);
 void	set_cheapest(t_stack *stack);
 t_stack	*get_cheapest(t_stack *stack);
 void	free_stack(t_stack **stack);
 void	free_and_exit(t_stack **stack);
 void	append_node(t_stack **stack, int n);
 t_stack	*find_min_value(t_stack *stack);
 t_stack	*find_max_value(t_stack *stack);
 void	min_on_top(t_stack **a);
 void	assign_index(t_stack *stack);
 void	set_current_position(t_stack *stack);
 void	init_nodes_a(t_stack *a, t_stack *b);
 void	init_nodes_b(t_stack *a, t_stack *b);
 void	set_target_in_b(t_stack *a, t_stack *b);
 void	set_target_in_a(t_stack *a, t_stack *b);
 int	is_sorted(t_stack *stack);
 void	parse_args(t_stack **stack_a, char **av);
 void	sa(t_stack **a);
 void	sb(t_stack **b);
 void	ss(t_stack **a, t_stack **b);
 void	pa(t_stack **a, t_stack **b);
 void	pb(t_stack **b, t_stack **a);
 void	ra(t_stack **a);
 void	rb(t_stack **b);
 void	rr(t_stack **a, t_stack **b);
 void	rra(t_stack **a);
 void	rrb(t_stack **b);
 void	rrr(t_stack **a, t_stack **b);
 long	ft_atol(const char *str);
 void	ft_putstr_fd(char *s, int fd);
 char	**ft_split(char const *s, char c);

#endif