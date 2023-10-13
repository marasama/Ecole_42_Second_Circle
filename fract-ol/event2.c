/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:49:04 by adurusoy          #+#    #+#             */
/*   Updated: 2023/10/13 09:54:19 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	init_x_y(t_t *t)
{
	t->x = ((t->x_x / (double)600) * (t->end_x - t->start_x)) + t->start_x;
	t->y = ((t->y_y / (double)600) * (t->end_y - t->start_y)) + t->start_y;
}

int	destroy_exit(t_t *t)
{
	mlx_destroy_image(t->ptr, t->image);
	mlx_destroy_window(t->ptr, t->win);
	exit (0);
	return (0);
}
