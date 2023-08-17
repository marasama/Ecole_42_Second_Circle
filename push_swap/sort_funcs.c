/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 07:37:56 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_num_node **a)
{
	t_num_node	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->correct_order);
		tmp = tmp->next;
	}
}

int	cost_calc(t_num_node **a, int order, int node_size, int option)
{
	t_num_node	*tmp;
	int			cost;

	tmp = *a;
	cost = 0;
	if (order == node_size && option == 2)
		order = 0;
	else if (order == 1 && option == 1)
		order = node_size + 1;
	while (tmp->correct_order != order - 1 && option == 1)
	{
		cost++;
		tmp = tmp->next;
	}
	while (tmp->correct_order != order + 1 && option == 2)
	{
		cost++;
		tmp = tmp->next;
	}
	if (node_size - cost < cost)
		return (-(node_size - cost));
	else
		return (cost);
}

int	compare_numbers(t_num_node **a, t_num_node **b, int node_size)
{
	t_num_node	*tmp;
	int			cost1;
	int			cost2;

	tmp = get_last_node(b);
	cost1 = cost_calc(a, (*b)->correct_order, node_size, 1);
	cost2 = cost_calc(a, tmp->correct_order, node_size, 2);
	if (cost1 == 0 || cost2 == 0)
		return (0);
	else if (cost1 < 0 && cost2 < cost1)
		return (-1);
	else if (cost1 > 0 && cost1 < cost2)
		return (1);
	else if (cost2 < 0 && cost1 < cost2)
		return (-2);
	else
		return (2);
}

void	push_b(t_num_node **a, t_num_node **b, int order, int option)
{
	if (order == node_count(a) + 1)
		order = 1;
	if (order == 0)
		order = node_count(a);
	while ((*a)->correct_order != order)
	{
		if (option < 0)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	if (option % 2 == 0)
		rb(b);
}

void	start_sorting(t_num_node **a, int node_size)
{
	t_num_node	*b;
	int			c;
	int			cost;

	b = NULL;
	pb(a, &b);
	c = node_size;
	while (c > 0)
	{
		cost = compare_numbers(a, &b, node_size);
		if (cost == 0)
			pb(a, &b);
		else if (cost % 2 == 0)
			push_b(a, &b, get_last_node(&b)->correct_order + 1, cost);
		else
			push_b(a, &b, b->correct_order - 1, cost);
		c--;
	}
}
