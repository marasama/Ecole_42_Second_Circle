/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:07:17 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/11 20:52:40 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrr(t_num_node **a, t_num_node **b)
{
	r_rev(a);
	r_rev(b);
	ft_printf("rrr\n");
}
