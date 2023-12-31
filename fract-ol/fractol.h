/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:49:37 by adurusoy          #+#    #+#             */
/*   Updated: 2023/10/13 09:55:36 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"

typedef struct s_t
{
	unsigned char	*ch;
	double			x;
	double			y;
	double			x_x;
	double			y_y;
	void			*ptr;
	void			*win;
	double			x_o;
	double			y_o;
	int				itier;
	double			xtmp;
	double			ytmp;
	void			*image;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	char			*name;
	double			start_y;
	double			end_y;
	double			start_x;
	double			end_x;
	int				zoom;
	int				stop;
	int				max;
	int				color;
}					t_t;

void				mandelbrot(t_t *t);
int					str_cmp(char *s1, char *s2);
int					mouse_press(int button, int x, int y, t_t *t);
int					key_press(int keycode, t_t *t);
void				key_press2(int keycode, t_t *t);
void				key_press3(int keycode, t_t *t);
void				julia(t_t *t);
void				check_julia(char **a, t_t *t);
void				menu(t_t *t);
void				itier_loop(t_t *t);
void				map(t_t *t);
double				ft_abs(double x);
double				after_point(double a);
void				set_color(t_t *t, int color);
void				check_ar(t_t *t);
void				init(t_t *t, char *str);
void				string_put(t_t *t);
void				zoom(t_t *t, double x, double y, double zoom);
void				mlx_ho(t_t *t);
void				init_x_y(t_t *t);
int					destroy_exit(t_t *t);

#endif
