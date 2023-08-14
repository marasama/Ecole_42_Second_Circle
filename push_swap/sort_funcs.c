/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/13 23:47:53 by adurusoy         ###   ########.fr       */
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

int		partition_size(int a)
{
	if (a <= 15)
		return (a);
	else if (a <= 60)
		return (a / 2);
	else if (a <= 120)
		return (a / 4);
	else if (a <= 240)
		return (a / 8);
	else if (a <= 480)
		return (a / 12);
	else
		return (a / 24);
}

void	push_a(t_num_node **a, t_num_node **b, int *order)
{
	while ((*b) != NULL)
	{
		if ((*b)->correct_order == (*order))
		{
			pa(a, b);
			ra(a);
			(*order)++;
		}
		else
			rb(b);
	}
}

void	push_b(t_num_node **a, t_num_node **b, int max_order, int order)
{
	t_num_node	*tmp;
	int			node_size;
	int			part_num;
	int			e;

	e = 0;
	node_size = node_count(a);
	part_num = partition_size(node_size);
	while (e < part_num)
	{
		if (order != 1 && (*a)->correct_order == 1)
		{
			tmp = get_nth_node(a, node_size);
			while (tmp->correct_order != order)
			{
				tmp = get_nth_node(a, node_size);
				rra(a);
			}
		}
		if ((*a)->correct_order <= max_order)
		{
			pb(a, b);
			e++;
		}
		else
			ra(a);
	}
}

void	start_sorting(t_num_node **a, int node_size)
{
	t_num_node	*b;
	int			part_num;
	int			max_order;
	int			order;

	b = NULL;
	part_num = partition_size(node_size);
	max_order = part_num;
	order = 1;
	while (!check_sort(a))
	{
		push_b(a, &b, max_order, order);
		push_a(a, &b, &order);
		max_order += part_num;
		if (max_order > node_count(a))
		{
			max_order = node_size;
			part_num = max_order;
		}
	}
}
