/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:06:47 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 06:07:04 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrb(t_num_node **b)
{
	t_num_node	*tmp;
	int			tmp_num;

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
	ft_printf("rrb\n");
}
