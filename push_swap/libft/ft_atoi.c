/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:08:18 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 20:22:03 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (str[b] == 48)
		b++;
	while (str[b] < 58 && str[b] > 47)
	{
		c = (c * 10) + (str[b] - 48);
		b++;
	}
	if (str[d] == '-')
		c = -c;
	return (c);
}