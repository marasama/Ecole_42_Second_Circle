/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 21:11:32 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_operations(t_num_node **a, t_num_node **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_b > 0)
	{
		rb(b, 1);
		cost_b--;
	}
	while (cost_a > 0)
	{
		ra(a, 1);
		cost_a--;
	}
}

void	rr_operations(t_num_node **a, t_num_node **b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b, 1);
		cost_a++;
		cost_b++;
	}
	while (cost_b < 0)
	{
		rrb(b, 1);
		cost_b++;
	}
	while (cost_a < 0)
	{
		rra(a, 1);
		cost_a++;
	}
}

void	push_back(t_num_node **a, t_num_node **b)
{
	int	cost;
	int	c;

	c = 4;
	cost = cost_a(b, get_min_max_order(b, 1));
	while (cost < 0)
	{
		rrb(b, 1);
		cost++;
	}
	while (cost > 0)
	{
		rb(b, 1);
		cost--;
	}
	while ((*b) != NULL)
	{
		while (get_last_node(a)->correct_order > (*b)->correct_order && --c > 0)
			rra(a, 1);
		pa(a, b, 1);
	}
	while (get_last_node(a)->correct_order < (*a)->correct_order)
		rra(a, 1);
}

void	start_sorting(t_num_node **a)
{
	t_num_node	*b;
	int			c;
	int			cost_a;
	int			cost_b;

	b = NULL;
	pb(a, &b, 1);
	pb(a, &b, 1);
	if (b->correct_order < b->next->correct_order)
		sb(&b, 1);
	c = node_count(a) - 3;
	while (c > 0)
	{
		cost_a = cost_calculator(a, &b, 1);
		cost_b = cost_calculator(a, &b, 2);
		r_operations(a, &b, cost_a, cost_b);
		rr_operations(a, &b, cost_a, cost_b);
		pb(a, &b, 1);
		c--;
	}
	triple_sort(a);
	push_back(a, &b);
}
