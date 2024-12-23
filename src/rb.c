/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:54:38 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/23 13:38:59 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **stack_b)
{
	t_node	*head;
	t_node	*new_head;
	t_node	*current;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	current = *stack_b;
	head = *stack_b;
	new_head = head->next;
	while (current->next != NULL)
		current = current->next;
	current->next = head;
	head->next = NULL;
	*stack_b = new_head;
}
