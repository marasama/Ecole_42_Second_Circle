/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:35:34 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/09 22:21:22 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	node_maker(t_num_node **a, int b)
{
	t_num_node	*c;

	c = (t_num_node *)malloc(sizeof(t_num_node));
	c->num = b;
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

int	node_count(t_num_node **a)
{
	t_num_node	*b;
	int			c;

	b = *a;
	c = 0;
	while (b->prev != NULL)
		b = b->prev;
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
	int			count;
	int			return_val;

	count = 0;
	return_val = 0;
	b = *a;
	tmp = b->num;
	while (b != NULL)
	{
		if (b->num < tmp)
		{
			tmp = b->num;
			return_val = count;
		}
		count++;
		b = b->next;
	}
	return (return_val);
}
