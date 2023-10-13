/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:49:04 by adurusoy          #+#    #+#             */
/*   Updated: 2023/10/13 04:49:08 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	simple_zoome1(t_t *t)
{
	if (t->start_x < 0 && t->start_y < 0 && t->end_x > 0 && t->end_y > 0)
	{
		t->start_x = t->start_x + 0.015;
		t->start_y = t->start_y + 0.015;
		t->end_x = t->end_x - 0.015;
		t->end_y = t->end_y - 0.015;
	}
}

void	simple_zoome2(t_t *t)
{
	t->start_x = t->start_x - 0.040;
	t->start_y = t->start_y - 0.040;
	t->end_x = t->end_x + 0.040;
	t->end_y = t->end_y + 0.040;
}

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
