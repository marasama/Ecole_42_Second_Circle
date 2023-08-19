/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:26:10 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 05:21:52 by adurusoy         ###   ########.fr       */
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
	else
		start_sorting(a, node_size);
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
