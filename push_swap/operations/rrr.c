/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:07:17 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 06:08:19 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrr(t_num_node **a, t_num_node **b)
{
	t_num_node	*tmp;
	int			tmp_num;

	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_num = tmp->num;
	while (tmp->prev != NULL)
	{
		tmp->num = tmp->prev->num;
		tmp = tmp->prev;
	}
	tmp->num = tmp_num;
	tmp = *b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_num = tmp->num;
	while (tmp->prev != NULL)
	{
		tmp->num = tmp->prev->num;
		tmp = tmp->prev;
	}
	tmp->num = tmp_num;
	ft_printf("rrr\n");
}