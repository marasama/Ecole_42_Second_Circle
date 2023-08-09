/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:11:23 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/09 21:07:36 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_num_node **a, t_num_node **b)
{
	t_num_node	*tmp;

	tmp = *b;
	node_maker(a, (*b)->num);
	(*b) = (*b)->next;
	free_node(&tmp, 1);
	ft_printf("pa\n");
}
