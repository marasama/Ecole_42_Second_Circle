/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/18 23:57:30 by adurusoy         ###   ########.fr       */
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

void	simple_sorts(t_num_node **a)
{
	if (node_count(a) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
	}
	else if (node_count(a) == 3)
		triple_sort(a);
}

void	triple_sort(t_num_node **a)
{
	if ((*a)->num > (*a)->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
		{
			ra(a);
			sa(a);
		}
		else if ((*a)->next->num < (*a)->next->next->num)
			ra(a);
		else
			sa(a);
	}
	else if ((*a)->num < (*a)->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
			rra(a);
		if (!check_sort(a))
			sa(a);
	}
}

void	rotate_operations(t_num_node **a, t_num_node **b, int *cost_a, int *cost_b)
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

void	rev_rotate_operations(t_num_node **a, t_num_node **b, int *cost_a, int *cost_b)
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
void	start_sorting(t_num_node **a)
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
		cost_a = cost_calculator(a, &b, 2);
		cost_b = cost_calculator(a, &b, 3);
		rotate_operations(a, &b, &cost_a, &cost_b);
		rev_rotate_operations(a, &b, &cost_a, &cost_b);
		pb(a, &b);
		c--;
	}
	triple_sort(a);
}
