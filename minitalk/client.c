/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:10:21 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/05 06:28:36 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	checkbit(int a, int b)
{
	int		c;
	int		check;

	c = 1 << b;
	check = a & c;
	if (check == 0)
		return (0);
	else
		return (1);
}

void	sendnumber(int a, int pid)
{
	int		b;				//  0 0 0 0 0 0 0 0
							//  1 1 0 1 0 0 0 0
	b = 7;
	while (b >= 0)
	{
		if (checkbit(a, b) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		b--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		c;

	if (argc != 3)
	{
		ft_printf("Argument number must be 3\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	c = 0;
	while (argv[2][c])
	{
		sendnumber((int)argv[2][c], pid);
		c++;
	}
	return (0);
}
