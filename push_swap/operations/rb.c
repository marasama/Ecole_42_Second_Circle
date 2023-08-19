/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:54:35 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 21:12:04 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rb(t_num_node **b, int option)
{
	if (node_count(b) == 2)
		sb(b, 1);
	else
	{
		r_node(b);
		if (option != 0)
			ft_printf("rb\n");
	}
}
