/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:35:34 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 09:00:37 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	node_maker(t_num_node **a, int b, int d)
{
	t_num_node	*c;

	c = (t_num_node *)malloc(sizeof(t_num_node));
	c->num = b;
	c->correct_order = d;
	c->next = *a;
	c->prev = NULL;
	if (*a != NULL)
		(*a)->prev = c;
	*a = c;
}

void	free_node(t_num_node **a, int b)
{
	t_num_node	*c;

	c = *a;
	if (b == 1)
	{
		if ((*a)->next != NULL)
			(*a)->next->prev = (*a)->prev;
		if ((*a)->prev != NULL)
			(*a)->prev->next = (*a)->next;
		(*a) = (*a)->next;
		free (c);
	}
	else
	{
		while (c->prev != NULL)
			c = c->prev;
		while ((*a) != NULL)
		{
			c = *a;
			(*a) = (*a)->next;
			free(c);
		}
	}
}

int node_count(t_num_node **a)
{
	t_num_node	*b;
	int			c;

	b = *a;
	c = 0;
	while (b != NULL)
	{
		c++;
		b = b->next;
	}
	return (c);
}

int	find_min_node(t_num_node **a)
{
	t_num_node	*b;
	int			tmp;

	b = *a;
	tmp = b->num;
	while (b != NULL)
	{
		if (b->num > tmp)
			tmp = b->num;
		b = b->next;
	}
	b = *a;
	while (b != NULL)
	{
		if (b->num < tmp && b->correct_order == 0)
			tmp = b->num;
		b = b->next;
	}
	return (tmp);
}

t_num_node	*get_last_node(t_num_node **b)
{
	t_num_node *tmp;

	tmp = *b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
