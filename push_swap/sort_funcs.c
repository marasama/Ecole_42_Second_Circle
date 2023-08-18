/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 01:46:10 by adurusoy         ###   ########.fr       */
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

void	r_operations(t_num_node **a, t_num_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
}

void	rr_operations(t_num_node **a, t_num_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

void	push_back(t_num_node **a, t_num_node **b, int node_size)
{
	int	cost;

	if (get_last_node(a)->correct_order == node_size)
		rra(a);
	cost = cost_a(b, node_size);
	while (cost < 0)
	{
		rrb(b);
		cost++;
	}
	while (cost > 0)
	{
		rb(b);
		cost--;
	}
	while ((*b) != NULL)
	{
		pa(a, b);
		while ((*a)->correct_order == get_last_node(a)->correct_order + 1)
			rra(a);
	}
}

void	start_sorting(t_num_node **a, int node_size)
{
	t_num_node	*b;
	int			c;
	int			cost_a;
	int			cost_b;

	b = NULL;
	pb(a, &b);
	pb(a, &b);
	if (b->correct_order < b->next->correct_order)
		sb(&b);
	c = node_count(a) - 3;
	while (c > 0)
	{
		cost_a = cost_calculator(a, &b, 1);
		cost_b = cost_calculator(a, &b, 2);
		r_operations(a, &b, &cost_a, &cost_b);
		rr_operations(a, &b, &cost_a, &cost_b);
		pb(a, &b);
		c--;
	}
	triple_sort(a);
	push_back(a, &b, node_size);
}
