/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:00:59 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/21 19:52:01 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **stack_b)
{
	t_node	*second;
	t_node	*third;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	second = (*stack_b)->next;
	third = second->next;
	(*stack_b)->next = third;
	second->next = *stack_b;
	*stack_b = second;
}
