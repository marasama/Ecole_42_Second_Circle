/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:26:10 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 21:12:38 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sorts(t_num_node **a, int node_size)
{
	if (node_size == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a, 1);
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
			ra(a, 1);
			sa(a, 1);
		}
		else if ((*a)->num < (*a)->next->next->num)
			sa(a, 1);
		else
			ra(a, 1);
	}
	else if ((*a)->num < (*a)->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
			rra(a, 1);
		if (!check_sort(a))
			sa(a, 1);
	}
}

void	quadra_sort(t_num_node **a)
{
	t_num_node	*b;
	int			cost;

	b = NULL;
	pb(a, &b, 1);
	triple_sort(a);
	if (b->correct_order == 4)
		cost = cost_a(a, 1);
	else
		cost = cost_a(a, b->correct_order + 1);
	while (cost < 0)
	{
		rra(a, 1);
		cost++;
	}
	while (cost > 0)
	{
		ra(a, 1);
		cost--;
	}
	pa(a, &b, 1);
	while ((*a)->correct_order != 1)
		ra(a, 1);
}
