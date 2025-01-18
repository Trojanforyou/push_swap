/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:57:56 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/18 20:49:42 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	if (stack_sorted(*a))
		return ;
	biggest_node = find_max(*a);
	if (*a == biggest_node)
		ra(a, false);
	if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_second_last(t_node **a, t_node **b)
{
		rra(a, false);
		rra(a, false);
		pb(b, a, false);
}
void	sort_four(t_node **a, t_node **b)
{
	t_node	*minimal_node;

	if (stack_sorted(*a))
		return ;
	minimal_node = find_min(*a);
	if (*a == minimal_node)
		pb(b, a, false);
	else if ((*a)->next == minimal_node)
	{
		sa(a, false);
		pb(b, a, false);
	}
	else if ((*a)->next->next == minimal_node)
	{
		ra(a, false);
		sa(a, false);
		pb(b, a, false);
	}
	else if ((*a)->next->next->next == minimal_node)
	{
		rra(a, false);
		pb(b, a, false);
	}
	sort_three(a);
	pa(a, b, false);
}


void	sort_last_pos(t_node **a, t_node **b)
{
	rra(a, false);
	pb(b, a, false);
}
void	sort_five(t_node **a, t_node **b)
{
	t_node	*minimal;

	minimal = find_min(*a);
	if (stack_sorted(*a))
		return ;
	else if (*a == minimal)
		pb(b, a, false);
	else if ((*a)->next == minimal)
	{
		sa(a, false);
		pb(b, a, false);
	}
	else if ((*a)->next->next == minimal)
	{
		ra(a, false);
		sa(a, false);
		pb(b, a, false );
	}
	else if ((*a)->next->next->next == minimal)
		sort_second_last(a, b);
	if ((*a)->next->next->next->next == minimal)
		sort_last_pos(a, b);
	sort_four(a, b);
	pa(a, b, false);
}
