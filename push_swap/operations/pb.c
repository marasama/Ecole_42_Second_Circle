/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:15:34 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/11 20:39:22 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pb(t_num_node **a, t_num_node **b)
{
	t_num_node	*tmp;

	tmp = *a;
	node_maker(b, (*a)->num, (*a)->correct_order);
	(*a) = (*a)->next;
	free_node(&tmp, 1);
	ft_printf("pb\n");
}
