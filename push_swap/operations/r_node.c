/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:58:00 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 05:04:45 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	r_node(t_num_node **a)
{
	t_num_node	*tmp;
	int			tmp_num;
	int			tmp_order;

	if (node_count(a) == 1)
		return;
	tmp = *a;
	tmp_num = tmp->num;
	tmp_order = tmp->correct_order;
	while (tmp->next != NULL)
	{
		tmp->num = tmp->next->num;
		tmp->correct_order = tmp->next->correct_order;
		tmp = tmp->next;
	}
	tmp->correct_order = tmp_order;
	tmp->num = tmp_num;
}
