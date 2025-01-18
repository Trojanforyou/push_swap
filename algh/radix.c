/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:30:51 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/18 21:31:55 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	int get_max_bits(t_node *stack)
{
	t_node	*tmp;
	int		max;
	int		max_bits;

	tmp = stack;
	max = tmp->value;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}


void	normalize_stack(t_node	**a)
{
	t_node	*tmp;
	int		min_value;

	tmp = *a;
	min_value = find_min(*a)->value;
	if (min_value < 0)
		min_value = -min_value;
	while (tmp)
	{
		tmp->value += min_value;
		tmp = tmp->next;
	}
}

void restore_stack(t_node **a)
{
	t_node *tmp = *a;
	int min_val = find_min(*a)->value;
	if (min_val < 0)
		min_val = -min_val;

	while (tmp)
	{
		tmp->value -= min_val;
		tmp = tmp->next;
	}
}

void radix_sort_stack_b(t_node **a, t_node **b, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size)
	{
		if ((((*b)->value >> j) & 1) == 0)
			ra(b, false);
		else
			pb(a, b, false);
	}
	while (*b)
		pb(a, b, false);
}

void radix_sort(t_node **a, t_node **b)
{
	int i = 0;
	int size = stack_len(*a);
	int max_bits = get_max_bits(*a);

	if (!a || !b)
		return ;
	normalize_stack(a);
	while (i < max_bits)
	{
		int j = 0;
		while (j < size)
		{
			if ((((*a)->value >> i) & 1) == 0)
				pb(b, a, false);
			else
				ra(a, false);
			j++;
		}
		radix_sort_stack_b(a, b, stack_len(*b), max_bits, i + 1);
		i++;
	}
	restore_stack(a);
	while (*b)
		pb(a, b, false);
}
