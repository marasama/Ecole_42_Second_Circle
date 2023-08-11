/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:06:02 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/12 00:28:57 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_num_node **a)
{
	t_num_node	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->correct_order);
		tmp = tmp->next;
	}
}

void	start_sorting(t_num_node **a)
{
}
