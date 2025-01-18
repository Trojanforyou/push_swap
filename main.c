/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:20:28 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/18 21:35:05 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "inc/push_swap.h"


void free_arr(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while(argv[i])
		{
			free(argv[i]);
			i++;
		}
	free(argv);
	}
}

static void	main_sort(t_node **a, t_node **b)
{
	
}
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		free_error(&a);
	else if (argc == 2)
	{
		argv = ft_splito(argv[1], ' ');
		if (!argv)
			free_error(&a);
	}
	stack_init(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 4)
			sort_four(&a, &b);
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		else
			radix_sort(&a, &b);
	}
	free_arr(argc, argv);
	free_stack(&a);

	return (0);
}
