/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:54:35 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 05:55:21 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rb(t_num_node **b)
{
	t_num_node	*tmp;
	int			tmp_num;

	tmp = *b;
	tmp_num = tmp->num;
	while (tmp->next != NULL)
	{
		tmp->num = tmp->next->num;
		tmp = tmp->next;
	}
	tmp->num = tmp_num;
	ft_printf("rb\n");
}
