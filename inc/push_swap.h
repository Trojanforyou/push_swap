/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:20:24 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/30 15:39:42 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "stdbool.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node *next;
	struct s_node *prev;
} t_node;

void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_b, t_node **stack_a);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
int		main(int argc, char **argv);
