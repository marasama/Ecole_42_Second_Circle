/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/18 21:02:10 by adurusoy         ###   ########.fr       */
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

void	start_sorting(t_num_node **a)
{
	t_num_node	*b;
	int			c;
	int			order;
	int			cost_a;
	int			cost_b;

	b = NULL;
	pb(a, &b);
	pb(a, &b);
	if (b->correct_order < b->next->correct_order)
		sb(&b);
	c = node_count(a) - 5;
	while (c > 0)
	{
		order = cost_calculator(a, &b, 1);
		cost_a = cost_calculator(a, &b, 2);
		cost_b = cost_calculator(a, &b, 3);
		while (cost_a < 0 && cost_b < 0)
		{
			rrr(a, &b);
			cost_a++;
			cost_b++;
		}
		while (cost_b < 0)
		{
			rrb(&b);
			cost_b++;
		}
		while (cost_a < 0)
		{
			rra(a);
			cost_a++;
		}
		while (cost_a > 0 && cost_b > 0)
		{
			rr(a, &b);
			cost_a--;
			cost_b--;
		}
		while (cost_b > 0)
		{
			rb(&b);
			cost_b--;
		}
		while (cost_a > 0)
		{
			ra(a);
			cost_a--;
		}
		pb(a, &b);
	}
}
