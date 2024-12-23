/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:09:08 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/23 17:14:22 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_node **stack_b)
{
	t_node	*head;
	t_node	*current;
	t_node	*tail;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	head = *stack_b;
	current = *stack_b;
	while (current->next && current->next->next)
		current = current->next;
	tail = current->next;
	current->next = NULL;
	tail->next = head;
	*stack_b = tail;
}
