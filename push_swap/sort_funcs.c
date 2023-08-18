/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 17:51:18 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_num_node **a)
{
	t_num_node	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->num);
		tmp = tmp->prev;
	}
}

void	start_sorting(t_num_node **a, int node_size)
{
	t_num_node	*b;
	int			c;
	int			cost;

	b = NULL;
	pb(a, &b);
	pb(a, &b);
	if (b->correct_order < b->next->correct_order)
		sb(&b);
	c = node_count(a) - 5;
	while (c > 0)
	{
	}
}
