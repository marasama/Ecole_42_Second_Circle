/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/12 07:15:03 by adurusoy         ###   ########.fr       */
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
		return (a / 3);
	else if (a <= 240)
		return (a / 6);
	else if (a <= 480)
		return (a / 12);
	else
		return (a / 24);
}

void	start_sorting(t_num_node **a)
{
	t_num_node	*b;
	int			c;
	int			d;
	int			e;
	int			f;

	b = NULL;
	c = partition_size(node_count(a));
	d = c;
	f = 1;
	while (!(check_sort(a) && (*a)->correct_order == 1))
	{
		e = 0;
		while (e < c)
		{
			if ((*a)->correct_order <= d)
			{
				pb(a, &b);
				e++;
			}
			else
				ra(a);
		}
		while (b != NULL)
		{
			if (b->correct_order == f)
			{
				pa(a, &b);
				ra(a);
				f++;
			}
			else
				rb(&b);
		}
		d += c;
		if (d > node_count(a))
			d = node_count(a);
	}
}
