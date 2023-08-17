/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 12:58:13 by adurusoy         ###   ########.fr       */
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

int	cost_calc(t_num_node **a, int order, int node_size, int option)
{
	t_num_node	*tmp;
	int			cost;

	tmp = *a;
	cost = 0;
	if (order == node_size && option == 2)
		return (2147483647);
	else if (order == 1 && option == 1)
		return (2147483647);
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
	cost1 = cost_calc(a, (*b)->correct_order, node_size, 1) + 1;
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
	while ((*a)->correct_order != order)
	{
		if (option < 0)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	if (option % 2 != 0)
		rb(b);
}

void	start_sorting(t_num_node **a, int node_size)
{
	t_num_node	*b;
	int			c;
	int			cost;

	b = NULL;
	pb(a, &b);
	c = node_count(a) - 1;
	while (c > 0)
	{
		cost = compare_numbers(a, &b, node_count(a));
		if (cost == 0)
			pb(a, &b);
		else if (cost % 2 == 0)
		{
			if (get_last_node(&b)->correct_order == node_size)
				push_b(a, &b, 1, cost);
			else
				push_b(a, &b, get_last_node(&b)->correct_order + 1, cost);
		}
		else
		{
			if (b->correct_order == 1)
				push_b(a, &b, node_size, cost);
			else
				push_b(a, &b, b->correct_order - 1, cost);
		}
		c--;
	}
}
