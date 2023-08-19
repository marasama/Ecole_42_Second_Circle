/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:00:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 21:08:52 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sb(t_num_node **b, int option)
{
	int		tmp;
	int		order;

	if (node_count(b) == 1)
		return ;
	tmp = (*b)->num;
	order = (*b)->correct_order;
	(*b)->num = (*b)->next->num;
	(*b)->correct_order = (*b)->next->correct_order;
	(*b)->next->num = tmp;
	(*b)->next->correct_order = order;
	if (option != 0)
		ft_printf("sb\n");
}
