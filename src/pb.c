/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:31:52 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/21 19:52:42 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_b, t_node **stack_a)
{
	t_node	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_a = temp;
	free(temp);
}
