/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:42:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/18 20:24:28 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	error_syntax(char *str_n)
{
	if (*str_n == '-' && ft_strlen(str_n) > 11)
		return (1);
	else if (ft_strlen(str_n) > 10)
		return (1);
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	str_n++;
	while (*str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
		str_n++;
	}
	return (0);
}

int	error_dup(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*curr;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	free_error(t_node **a)
{

	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
