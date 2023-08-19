/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:26:10 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 09:12:57 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sorts(t_num_node **a, int node_size)
{
	if (node_size == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
	}
	else if (node_size == 3)
		triple_sort(a);
	else if (node_size == 4)
		quadra_sort(a);
	else
		start_sorting(a);
}

void	triple_sort(t_num_node **a)
{
	if (check_sort(a))
		return ;
	if ((*a)->num > (*a)->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
		{
			ra(a);
			sa(a);
		}
		else if ((*a)->num < (*a)->next->next->num)
			sa(a);
		else
			ra(a);
	}
	else if ((*a)->num < (*a)->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
			rra(a);
		if (!check_sort(a))
			sa(a);
	}
}

void	quadra_sort(t_num_node **a)
{
	t_num_node	*b;
	int			cost;

	b = NULL;
	pb(a, &b);
	triple_sort(a);
	if (b->correct_order == 4)
		cost = cost_a(a, 1);
	else
		cost = cost_a(a, b->correct_order + 1);
	while (cost < 0)
	{
		rra(a);
		cost++;
	}
	while (cost > 0)
	{
		ra(a);
		cost--;
	}
	pa(a, &b);
	while ((*a)->correct_order != 1)
		ra(a);
}
