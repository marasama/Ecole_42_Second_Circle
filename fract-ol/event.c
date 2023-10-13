/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:47:39 by adurusoy          #+#    #+#             */
/*   Updated: 2023/10/13 04:48:46 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_press(int button, int x, int y, t_t *t)
{
	if (button == 5 && t->stop == 1)
		zoom(t, (double)x, (double)y, 1.1);
	else if (button == 4 && t->stop == 1)
		zoom(t, (double)x, (double)y, 0.9);
	check_ar(t);
	return (1);
}

void	key_press2(int keycode, t_t *t)
{
	if (keycode == 123)
	{
		t->start_x = t->start_x - 0.037;
		t->end_x = t->end_x - 0.037;
		check_ar(t);
	}
	else if (keycode == 126)
	{
		t->start_y = t->start_y - 0.037;
		t->end_y = t->end_y - 0.037;
		check_ar(t);
	}
	else if (keycode == 125)
	{
		t->start_y = t->start_y + 0.037;
		t->end_y = t->end_y + 0.037;
		check_ar(t);
	}
	else if (keycode == 24)
	{
		t->max += 10;
		check_ar(t);
	}
	else
		key_press3(keycode, t);
}

int	key_press(int keycode, t_t *t)
{
	if (keycode == 53)
	{
		destroy_exit(t);
	}
	else if (keycode == 69 && t->stop == 1)
	{
		simple_zoome1(t);
		check_ar(t);
	}
	else if (keycode == 78 && t->stop == 1)
	{
		simple_zoome2(t);
		check_ar(t);
	}
	else if (keycode == 27)
	{
		if (t->max >= 10)
			t->max -= 10;
		check_ar(t);
	}
	else
		key_press2(keycode, t);
	return (1);
}

void	key_press3(int keycode, t_t *t)
{
	if (keycode == 49)
	{
		if (t->stop == 0)
			t->stop = 1;
		else
			t->stop = 0;
		check_ar(t);
	}
	else if (keycode == 36)
	{
		t->color = t->color * 11;
		check_ar(t);
	}
	if (keycode == 82)
	{
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 124)
	{
		t->start_x = t->start_x + 0.037;
		t->end_x = t->end_x + 0.037;
		check_ar(t);
	}
}

double	after_point(double a)
{
	if (a > 0)
	{
		while (a > 1)
			a /= 10;
	}
	else
	{
		while (a < -1)
			a /= 10;
	}
	return (a);
}
