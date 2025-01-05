/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:49:48 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/04 16:03:27 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_node	set_target_b(t_node *a, t_node *b)
{
	long	best_match_value;

	best_match_value = LONG_MAX;

	if (!b)
		return ;
	while (b)
	{
		while (a)
			a = a->next;
		if (b )

	}
}
