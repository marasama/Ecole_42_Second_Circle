#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void	handle_sigusr(int signum)
{
	static unsigned int bit = 1048576;
	static int b = 0;
	static int sender_pid = 0;
	static int check = 0;

	if (signum == SIGUSR2)	
		b += bit;
	bit /= 2;
	if (check == 1)
		kill(sender_pid, SIGUSR1);
	if (bit == 0)
	{
		if (sender_pid == 0)
		{
			sender_pid = b;
			check = 1;
		}
		else
			write(1, &b, 1);
		bit = 1048576;
		b = 0;
	}
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	printf("%d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
