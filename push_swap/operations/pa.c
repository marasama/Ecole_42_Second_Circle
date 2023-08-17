/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:11:23 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/17 07:53:20 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_num_node **a, t_num_node **b)
{
	t_num_node	*tmp;

	tmp = *b;
	node_maker(a, (*b)->num, (*b)->correct_order);
	(*b) = (*b)->next;
	free(tmp);
	ft_printf("pa\n");
}
