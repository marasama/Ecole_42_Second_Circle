/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:50:49 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 18:26:10 by adurusoy         ###   ########.fr       */
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
	int			tmp_num;
	int			cost;

	tmp = *a;
	cost = 0;
	tmp_num = 0;
	if (order > get_min_max_order(a, 1) || order < get_min_max_order(a, 2))
	{
		while (tmp != get_min_max_order(a, 1))
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
	t_num_node *tmp;
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

int	cost_calcutor(t_num_node **a, t_num_node **b, int option)
{
	t_num_node	*tmp;
	int			cost;
	int			order;
	int			cost_a;

	tmp = *a;
	cost = 2147483647;
	order = 0;
	cost_a = 0;
	while (tmp != NULL)
	{
		if (cost_a + ft_abs(cost_b(b, tmp->correct_order)) < cost)
			order = tmp->correct_order;
		cost_a++;
		if (cost_a == (node_count(a) / 2));
			cost_a = 0;
		tmp = tmp->next;
	}
	if (option == 1)
		return (order);
}
