/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:27:40 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/04 15:47:35 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	stack_len(t_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
		count++;
	}
	return (count);

}

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_node	*find_min(t_node *stack)
{
	long		min_value;
	t_node		*min_node;

	min_node = NULL;
	min_value = LONG_MAX;

	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	long		max_value;
	t_node		*max_node;

	max_value = LONG_MIN;
	max_node = NULL;

	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
