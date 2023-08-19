/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:44:21 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 04:00:36 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_max_order(t_num_node **b, int option)
{
	t_num_node	*tmp;
	int			tmp_num;

	tmp = *b;
	tmp_num = tmp->correct_order;
	tmp = tmp->next;
	while (tmp != NULL && option == 1)
	{
		if (tmp->correct_order > tmp_num)
			tmp_num = tmp->correct_order;
		tmp = tmp->next;
	}
	while (tmp != NULL && option == 2)
	{
		if (tmp->correct_order < tmp_num)
			tmp_num = tmp->correct_order;
		tmp = tmp->next;
	}
	return (tmp_num);
}

int	min_max_cost_calc(t_num_node **a, int order)
{
	t_num_node	*tmp;
	int			cost;

	tmp = *a;
	cost = 0;
	if (order > get_min_max_order(a, 1) || order < get_min_max_order(a, 2))
	{
		while (tmp->correct_order != get_min_max_order(a, 1))
		{
			tmp = tmp->next;
			cost++;
		}
	}
	if (cost > node_count(a) - cost)
		return (cost - node_count(a));
	else
		return (cost);
}

int	get_place_cost(t_num_node **b, int order)
{
	t_num_node	*tmp;
	int			tmp_num;
	int			tmp_cost;
	int			cost;

	tmp = *b;
	tmp_num = 0;
	cost = 0;
	tmp_cost = 0;
	while (tmp != NULL)
	{
		if (tmp->correct_order > tmp_num && tmp->correct_order < order)
		{
			tmp_num = tmp->correct_order;
			tmp_cost = cost;
		}
		cost++;
		tmp = tmp->next;
	}
	return (tmp_cost);
}
