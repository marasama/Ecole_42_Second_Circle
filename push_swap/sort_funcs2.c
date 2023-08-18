/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:26:10 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 02:21:16 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sorts(t_num_node **a)
{
	if (node_count(a) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
	}
	else if (node_count(a) == 3)
		triple_sort(a);
	else if (node_count(a) == 4)
		quadra_sort(a);
}

void	triple_sort(t_num_node **a)
{
	if ((*a)->num > (*a)->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
		{
			ra(a);
			sa(a);
		}
		else if ((*a)->next->num < (*a)->next->next->num)
			ra(a);
		else
			sa(a);
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
	t_num_node *tmp;

	while (get_last_node(a)->correct_order != 4)
		ra(a);
	tmp = get_last_node(a);
	free_node(&tmp, 1);
	triple_sort(a);
}

void	penta_sort(t_num_node **a)
{
	t_num_node *tmp;

	while (get_last_node(a)->correct_order != 5)
		ra(a);
	tmp = get_last_node(a);
	free_node(&tmp, 1);
	quadra_sort(a);
}
