/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:01:12 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 06:06:37 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_num_node **a)
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
	ft_printf("rra\n");
}
