/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:35:34 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 05:07:46 by adurusoy         ###   ########.fr       */
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
	if (a != NULL)
		(*a)->prev = c;
	*a = c;
}

void	free_node(t_num_node **a, int b)
{
	t_num_node	*c;

	if (b == 1)
	{
		c = *a;
		*a = (*a)->next;
		free (c);
	}
	else
	{
		while ((*a) != NULL)
		{
			c = *a;
			*a = (*a)->next;
			free(c);
		}
	}
}
