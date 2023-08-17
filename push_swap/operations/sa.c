/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:55:26 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 05:06:19 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_num_node **a)
{
	int		tmp;
	int		order;

	if (node_count(a) == 1)
		return;
	tmp = (*a)->num;
	order = (*a)->correct_order;
	(*a)->num = (*a)->next->num;
	(*a)->correct_order = (*a)->next->correct_order;
	(*a)->next->num = tmp;
	(*a)->next->correct_order = order;
	ft_printf("sa\n");
}
