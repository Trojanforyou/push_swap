/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:51:43 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/23 17:08:16 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*tail;
	t_node	*current;
	t_node	*head;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	current = *stack_a;
	while (current->next && current->next->next)
		current = current->next;
	tail = current->next;
	current->next = NULL;
	tail->next = head;
	*stack_a = tail;
}
