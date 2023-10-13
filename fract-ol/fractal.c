/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 03:16:04 by adurusoy          #+#    #+#             */
/*   Updated: 2023/10/13 04:26:14 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < 600)
	{
		t->x_x = 0;
		while (t->x_x < 600)
		{
			t->itier = 0;
			init_x_y(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	t->stop = 1;
	mlx_ho(t);
}

void	mandelbrot(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < 600)
	{
		t->x_x = 0;
		while (t->x_x < 600)
		{
			t->itier = 0;
			map(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	t->stop = 1;
	mlx_ho(t);
}

void	zoom(t_t *t, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / 600) * (t->end_x - t->start_x)) + t->start_x;
	yy = ((y / 600) * (t->end_y - t->start_y)) + t->start_y;
	t->start_x = xx + ((t->start_x - xx) * zoom);
	t->start_y = yy + ((t->start_y - yy) * zoom);
	t->end_y = yy + ((t->end_y - yy) * zoom);
	t->end_x = xx + ((t->end_x - xx) * zoom);
	if (t->max <= 120)
		t->max += 2;
}

void	mlx_ho(t_t *t)
{
	menu(t);
	mlx_hook(t->win, 4, 1, mouse_press, t);
	mlx_hook(t->win, 2, 1, key_press, t);
	mlx_hook(t->win, 17, 1, destroy_exit, t);
	mlx_loop(t->ptr);
}
