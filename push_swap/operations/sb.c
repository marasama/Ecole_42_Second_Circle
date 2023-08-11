/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:00:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/11 20:54:57 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sb(t_num_node **b)
{
	int		tmp;
	int		order;

	tmp = (*b)->num;
	order = (*b)->correct_order;
	(*b)->num = (*b)->next->num;
	(*b)->correct_order = (*b)->next->correct_order;
	(*b)->next->num = tmp;
	(*b)->next->correct_order = order;
	ft_printf("sb\n");
}
