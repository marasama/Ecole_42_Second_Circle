/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:48:14 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 07:26:31 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_num_node **a)
{
	if (node_count(a) == 2)
		sa(a);
	else
	{
		r_node(a);
		ft_printf("ra\n");
	}
}
