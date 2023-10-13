/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:19:41 by adurusoy          #+#    #+#             */
/*   Updated: 2023/10/13 09:50:49 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./ft_printf/ft_printf.h"
#include <stdlib.h>

int	ft_strlen(char *a)
{
	int		b;

	b = 0;
	while (a[b])
		b++;
	return (b);
}

int	atoi_check(char *s)
{
	int		b;

	b = 0;
	if (s[b] == '-' || s[b] == '+')
		b++;
	while (s[b] < 58 && s[b] > 47)
		b++;
	if (b == 1 && (s[0] == '+' || s[0] == '-'))
		return (0);
	return (b);
}

int	ft_atoi(const char *str)
{
	int		b;
	int		c;
	int		d;

	b = 0;
	c = 0;
	d = 0;
	while (str[b] == 32 || (str[b] <= 13 && str[b] >= 9))
		b++;
	if (str[b] == '-' || str[b] == '+')
	{
		d = b;
		b++;
	}
	while (str[b] < 58 && str[b] > 47)
	{
		c = (c * 10) + (str[b] - 48);
		b++;
	}
	if (str[d] == '-')
	{
		c = -c;
	}
	return (c);
}

int	check_int(char *a, int b)
{
	if (!a[0])
		return (0);
	if (ft_strlen(a) != atoi_check(a))
		return (0);
	if (b % 2 == 0 && ft_abs(ft_atoi(a)) > 2)
		return (0);
	if (b % 2 == 1 && atoi_check(a) > 9)
		return (0);
	return (1);
}

void	check_julia(char **a, t_t *t)
{
	int		b;
	double	x;
	double	y;

	b = 2;
	init(t, a[1]);
	while (b < 6)
	{
		if (check_int(a[b], b) == 0)
		{
			ft_printf("Wrong number input...\n");
			ft_printf("Numbers that before the dot must be between -2 and 2\n");
			ft_printf("Numbers that after the dot must be max 9 digit\n");
			exit(0);
		}
		b++;
	}
	x = after_point((double)ft_atoi(a[3]));
	y = after_point((double)ft_atoi(a[5]));
	x += (double)ft_atoi(a[2]);
	y += (double)ft_atoi(a[4]);
	t->x_o = x;
	t->y_o = y;
}
