/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:50:49 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/18 22:29:19 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	cost_b(t_num_node **b, int order)
{
	t_num_node	*tmp;
	int			cost;

	tmp = *b;
	cost = 0;
	cost = min_max_cost_calc(b, order);
	if (cost != 0)
		return (cost);
	cost = get_place_cost(b, order);
	if (cost > node_count(b) - cost)
		return (node_count(b) - cost);
	else
		return (cost);
}

int	cost_a(t_num_node **a, int order)
{
	t_num_node	*tmp;
	int			cost;

	cost = 0;
	tmp = *a;
	while (tmp->correct_order != order)
	{
		cost++;
		tmp = tmp->next;
	}
	if (cost > node_count(a) - cost)
		return (node_count(a) - cost);
	else
		return (cost);
}

int	cost_calculator(t_num_node **a, t_num_node **b, int option)
{
	t_num_node	*tmp;
	int			cost;
	int			order;
	int			tmp_cost_a;
	int			tmp_cost_b;

	tmp = *a;
	cost = 2147483647;
	order = 0;
	while (tmp != NULL)
	{
		tmp_cost_a = ft_abs(cost_a(a, tmp->correct_order));
		tmp_cost_b = ft_abs(cost_b(b, tmp->correct_order));
		if (tmp_cost_a + tmp_cost_b < cost)
		{
			order = tmp->correct_order;
			cost = tmp_cost_a + tmp_cost_b;
		}
		tmp = tmp->next;
	}
	return (ret_calc(order, cost_a(a, order), cost_b(b, order), option));
}
