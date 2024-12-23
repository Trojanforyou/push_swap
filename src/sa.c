/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:56:21 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/21 19:51:47 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*third;
	t_node	*second;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	second = (*stack_a)->next;
	third = second->next;
	(*stack_a)-> next = third;
	second -> next = *stack_a;
	*stack_a = second;
}
