/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:15:34 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 21:06:21 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pb(t_num_node **a, t_num_node **b, int option)
{
	t_num_node	*tmp;

	tmp = *a;
	node_maker(b, (*a)->num, (*a)->correct_order);
	(*a) = (*a)->next;
	free(tmp);
	if (option != 0)
		ft_printf("pb\n");
}
