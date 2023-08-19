/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:48:14 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 21:12:00 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_num_node **a, int option)
{
	if (node_count(a) == 2)
		sa(a, 1);
	else
	{
		r_node(a);
		if (option != 0)
			ft_printf("ra\n");
	}
}
