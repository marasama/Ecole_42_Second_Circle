/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:50:26 by adurusoy          #+#    #+#             */
/*   Updated: 2023/10/13 04:50:28 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./ft_printf/ft_printf.h"

void	menu(t_t *t)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 600)
	{
		i = 599;
		while (++i < 1000)
		{
			t->index = (j * 1000 * 4) + (i * 4);
			t->ch[t->index] = 189;
			t->ch[t->index + 1] = 87;
			t->ch[t->index + 2] = 54;
			t->ch[t->index + 3] = 0;
		}
	}
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	string_put(t);
}

void	string_put(t_t *t)
{
	mlx_string_put(t->ptr, t->win, 650, 20, 0xFFFFFF,
		"-------------ZOOM-------------");
	mlx_string_put(t->ptr, t->win, 635, 40, 0xf7b079,
		"               + | -              ");
	mlx_string_put(t->ptr, t->win, 635, 60, 0xf7b079,
		"       Scroll UP | Scroll DOWN         ");
	mlx_string_put(t->ptr, t->win, 650, 110, 0xFFFFFF,
		"-------------MOVE------------");
	mlx_string_put(t->ptr, t->win, 635, 140, 0xf7b079,
		"        Arrow UP | Arrow DOWN    ");
	mlx_string_put(t->ptr, t->win, 635, 180, 0xf7b079,
		"     Arrow RIGHT | Arrow LEFT ");
	mlx_string_put(t->ptr, t->win, 650, 220, 0xFFFFFF,
		"--------CHANGE COLOR-------");
	mlx_string_put(t->ptr, t->win, 635, 260, 0xf7b079,
		"           BUTTON (enter) ");
	mlx_string_put(t->ptr, t->win, 650, 300, 0xFFFFFF,
		"--------RESTART FRACTAL-------");
	mlx_string_put(t->ptr, t->win, 635, 340, 0xf7b079,
		"           BUTTON (0) ");
	mlx_string_put(t->ptr, t->win, 650, 380, 0xe13661,
		"-------------AUTHOR-----------");
	mlx_string_put(t->ptr, t->win, 650, 420, 0x2AB613,
		"------------adurusoy----------");
}

void	init(t_t *t, char *str)
{
	t->start_x = -2;
	t->end_x = 2;
	t->start_y = -2;
	t->end_y = 2;
	t->x_o = -0.4;
	t->y_o = 0.6;
	t->zoom = 0;
	t->stop = 0;
	t->max = 40;
	t->color = 20;
	t->name = str;
}

void	check_ar(t_t *t)
{
	if (str_cmp(t->name, "Mandelbrot") == 0)
		mandelbrot(t);
	else if (str_cmp(t->name, "Julia") == 0)
		julia(t);
}

int	main(int ac, char *av[])
{
	t_t		t;

	if ((ac >= 2) && (((str_cmp(av[1], "Mandelbrot") == 0) && ac == 2)
			|| ((str_cmp(av[1], "Julia") == 0) && ac == 6)))
	{
		init(&t, av[1]);
		if (ac == 6)
			check_julia(av, &t);
		t.ptr = mlx_init();
		t.win = mlx_new_window(t.ptr, 600 + 400, 600, "Fractol");
		t.image = mlx_new_image(t.ptr, 600 + 400, 600);
		t.ch = (unsigned char *)mlx_get_data_addr(t.image, &t.bpp,
				&t.size_l, &t.endian);
		check_ar(&t);
	}
	else
	{
		ft_printf("Usage: ./fractol <name> <parameters>\n");
		ft_printf("Parameters:\n-Mandelbrot\n");
		ft_printf("-Julia [x->before dot][x->after dot]");
		ft_printf("[y->before dot][y->after dot]\n");
	}
	return (0);
}
