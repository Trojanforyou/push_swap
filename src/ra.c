/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:43:35 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/23 13:32:47 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*head;
	t_node	*new_head;
	t_node	*current;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	current = *stack_a;
	head = *stack_a;
	new_head = head->next;
	while (current->next != NULL)
		current = current->next;
	current->next = head;
	head->next = NULL;
	(*stack_a)->next = new_head;
	*stack_a = new_head;
}
