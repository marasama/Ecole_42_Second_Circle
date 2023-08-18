/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:02:17 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/18 19:50:32 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ss(t_num_node **a, t_num_node **b)
{
	int		tmp;
	int		order;

	if (node_count(a) == 1)
		return ;
	tmp = (*a)->num;
	order = (*a)->correct_order;
	(*a)->num = (*a)->next->num;
	(*a)->correct_order = (*a)->next->correct_order;
	(*a)->next->num = tmp;
	(*a)->next->correct_order = order;
	tmp = (*b)->num;
	order = (*b)->correct_order;
	(*b)->num = (*b)->next->num;
	(*b)->correct_order = (*b)->next->correct_order;
	(*b)->next->num = tmp;
	(*b)->next->correct_order = order;
	ft_printf("ss\n");
}
