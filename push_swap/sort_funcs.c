/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/15 02:55:40 by adurusoy         ###   ########.fr       */
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

int		cost_calc(t_num_node **a, int order, int node_size, int option)
{
	t_num_node	*tmp;
	int			prev_cost;
	int			next_cost;

	tmp = *a;
	prev_cost = 0;
	next_cost = 0;
	while (tmp->correct_order != order - 1 && option == 1)
	{
		prev_cost++;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp->correct_order != order + 1 && order + 1 <= node_size && option == 2)
	{
		next_cost++;
		tmp = tmp->next;
	}
	if (node_size - prev_cost < prev_cost && option == 1)
		return ((node_size - prev_cost) * -1);
	else if (option == 1)
		return (prev_cost);
	if (node_size - next_cost < next_cost && option == 2)
		return ((node_size - next_cost) * -1);
	else
		return (next_cost);
}

t_num_node	*get_last_node(t_num_node **b)
{
	t_num_node *tmp;

	tmp = *b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);

}

int	compare_numbers(int a, int b)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a > b)
		return (0);
	else
		return (1);
}

void	start_sorting(t_num_node **a, int node_size)
{
	t_num_node	*b;
	int			c;
	int			cost1;
	int			cost2;

	b = NULL;
	pb(a, &b);
	c = node_size;
	while (c > 0)
	{
		cost1 = 2147483647;
		cost2 = 2147483647;
		if (b->correct_order - 1 != 0)
			cost1 = cost_calc(a, b->correct_order, node_size, 1);
		if (get_last_node(&b)->correct_order + 1 <= node_size)
			cost2 = cost_calc(a, get_last_node(&b)->correct_order, node_size, 2);
		if (cost1 == 0 || cost2 == 0)
			pb(a, &b);
		else if (compare_numbers(cost1, cost2))
		{
			while ((*a)->correct_order != b->correct_order - 1)
			{
				if (cost1 < 0)
					rra(a);
				else
					ra(a);
			}
			pb(a, &b);
			rb(&b);
		}
		else
		{
			while ((*a)->correct_order != get_last_node(&b)->correct_order + 1)
			{
				if (cost2 < 0)
					rra(a);
				else
					ra(a);
			}
			pb(a, &b);
		}
		c--;
	}
}
