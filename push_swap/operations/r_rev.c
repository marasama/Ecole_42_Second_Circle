/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:49:37 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/18 19:51:00 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	r_rev(t_num_node **a)
{
	t_num_node	*tmp;
	int			tmp_num;
	int			tmp_order;

	if (node_count(a) == 1)
		return ;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_num = tmp->num;
	tmp_order = tmp->correct_order;
	while (tmp->num != (*a)->num)
	{
		tmp->num = tmp->prev->num;
		tmp->correct_order = tmp->prev->correct_order;
		tmp = tmp->prev;
	}
	tmp->correct_order = tmp_order;
	tmp->num = tmp_num;
}
