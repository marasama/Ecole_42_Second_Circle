/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:11:57 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/04 21:45:27 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		{
			sender_pid = b;
			if (b == 0)
				ft_printf("\n");
			else
				ft_printf("Sender PID: %d\n", sender_pid);
		}
		else
		{
			write(1, &b, 1);
			kill(sender_pid, SIGUSR1);
		}
		bit = 1048576;
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
