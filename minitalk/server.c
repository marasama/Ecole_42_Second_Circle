/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:11:57 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/04 21:47:55 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int signum)
{
	static unsigned int		bit = 128;
	static int				b = 0;

	if (signum == SIGUSR2)
		b += bit;
	bit /= 2;
	if (bit == 0)
	{
		write(1, &b, 1);
		bit = 128;
		b = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, &handle_sigusr);
	signal(SIGUSR2, &handle_sigusr);
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
