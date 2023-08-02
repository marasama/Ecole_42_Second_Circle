/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:11:57 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/02 21:51:48 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int signum)
{
	static unsigned int		bit = 1048576;
	static int				b = 0;
	static int				sender_pid = 0;

	if (signum == SIGUSR2)
		b += bit;
	bit /= 2;
	if (bit == 0)
	{
		if (sender_pid == 0 || b == 0)
			sender_pid = b;
		else
		{
			write(1, &b, 1);
		}
		kill(sender_pid, SIGUSR1);
		bit = 1048576;
		b = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	ft_printf("%d", getpid());
	ft_printf("\n");
	while (1)
	{
		pause();
	}
	return (0);
}
