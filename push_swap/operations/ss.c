/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:02:17 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 05:04:14 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ss(t_num_node **a, t_num_node **b)
{
	int		tmp;

	tmp = (*b)->num;
	(*b)->num = (*b)->next->num;
	(*b)->next->num = tmp;
	tmp = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = tmp;
	ft_printf("ss\n");
}
