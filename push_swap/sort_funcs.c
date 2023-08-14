/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/14 22:37:39 by adurusoy         ###   ########.fr       */
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

void	start_sorting(t_num_node **a, int node_size)
{
	t_num_node	*b;
	int			tmp_num;
	int			c;
	int			d;

	b = NULL;
	d = 1;
	if ((*a)->correct_order == d)
		d++;
	tmp_num = (*a)->num;
	pb(a, &b);
	c = node_count(a);
	while (c > 0)
	{
		if ((*a)->correct_order == d)
		{
			ra(a);
			d++;
		}
		else
		{
			pb(a, &b);
			if (b->num > tmp_num)
				rb(&b);
		}
		c--;
	}
}
