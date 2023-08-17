/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:00:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 05:06:40 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sb(t_num_node **b)
{
	int		tmp;
	int		order;

	if (node_count(b) == 1)
		return;
	tmp = (*b)->num;
	order = (*b)->correct_order;
	(*b)->num = (*b)->next->num;
	(*b)->correct_order = (*b)->next->correct_order;
	(*b)->next->num = tmp;
	(*b)->next->correct_order = order;
	ft_printf("sb\n");
}
