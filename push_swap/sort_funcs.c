/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/09 02:18:41 by adurusoy         ###   ########.fr       */
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
		tmp = tmp->next;
	}
}

/* void	select_node_value(t_num_node **a)
{
	int		b;
	int		c;
	t_num_node *tmp;

	b = node_count(a);
	tmp =
	while((*a)->num != )
}
 */
void	start_sorting(t_num_node **a, t_num_node **b)
{
	t_num_node *c;
	int			d;
	int			e;
	int			f;

	d = node_count(a);
	c = *a;
	while ((*a)->next != NULL)
	{
		f = find_min_node(a);
		e = 0;
		while (e < f)
		{
			if (d - f >= f)
				ra(a);
			else if (d - f < f)
				rra(a);
			e++;
		}
		pb(a, b);
	}
	while ((*b) != NULL)
		pa(a, b);
}
