/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:20:24 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/18 21:26:55 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node 	*next;
	struct s_node 	*prev;
}	t_node;

void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);

int		error_syntax(char *str_n);
int		error_dup(t_node *a, int n);
void	free_stack(t_node **stack);
void	free_error(t_node **a);

void	stack_init(t_node **a, char **argv);
long	ft_atol(const char *s);
bool	stack_sorted(t_node *stack);
int		stack_len(t_node *stack);
t_node	*find_last(t_node *stack);
char	**ft_splito(char *s, char c);
t_node	*find_max(t_node *stack);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
t_node	*find_min(t_node *stack);
void	sort_five(t_node **a, t_node **b);

void	sort_last_pos(t_node **a, t_node **b);
void index_stack(t_node *stack);
void radix_sort(t_node **a, t_node **b);

#endif


