/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:50:49 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/24 13:21:23 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_b(t_num_node **b, int order)
{
	int			cost;

	cost = 0;
	cost = min_max_cost_calc(b, order);
	if (cost != 0)
		return (cost);
	cost = get_place_cost(b, order);
	if (cost > node_count(b) - cost)
		return (cost - node_count(b));
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
		return (cost - node_count(a));
	else
		return (cost);
}

int	rr_cost(int a, int b)
{
	int		cost;

	cost = 0;
	while (a < 0 && b < 0)
	{
		cost++;
		a++;
		b++;
	}
	while (b < 0)
	{
		cost++;
		b++;
	}
	while (a < 0)
	{
		cost++;
		a++;
	}
	return (cost);
}

int	r_cost(int a, int b)
{
	int		cost;

	cost = 0;
	while (a > 0 && b > 0)
	{
		cost++;
		a--;
		b--;
	}
	while (b > 0)
	{
		cost++;
		b--;
	}
	while (a > 0)
	{
		cost++;
		a--;
	}
	return (cost);
}

int	cost_calculator(t_num_node **a, t_num_node **b, int option)
{
	t_num_node	*tmp;
	int			cost;
	int			order;
	int			a_cost;
	int			b_cost;

	tmp = *a;
	cost = 2147483647;
	while (tmp != NULL)
	{
		a_cost = cost_a(a, tmp->correct_order);
		b_cost = cost_b(b, tmp->correct_order);
		if (r_cost(a_cost, b_cost) + rr_cost(a_cost, b_cost) < cost)
		{
			order = tmp->correct_order;
			cost = r_cost(a_cost, b_cost) + rr_cost(a_cost, b_cost);
		}
		tmp = tmp->next;
	}
	if (option == 1)
		return (cost_a(a, order));
	else
		return (cost_b(b, order));
}
