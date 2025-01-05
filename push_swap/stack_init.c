/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:16:01 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/03 15:29:03 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include "libft.h"

long	atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s >= 9 && *s <= 13 || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		result *= 10;
		result += *s - '0';
		s++;
	}
	return (result * sign);
}


static void	append_node(t_node **stack,int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = NULL;
	}
}

void	init_stack_a(t_node	**a, char **argv)
{
	long	n;
	int		i;

	i = 0;

	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_error(a);
		n = ft_atol(argv[i]);
		if (i > INT_MAX || i < INT_MIN)
			free_error(a);
		if (error_dup(*a, (int)n))
			error_free(a);
		append_node(a , (int)n);
		i++;

	}
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{

	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else if (!top_node->above_median)
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else if (!top_node->above_median)
				rrb(stack);
		}
	}
}
