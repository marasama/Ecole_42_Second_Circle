#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int bit = 0;
int a = 0;

void handle_usr2(int signum);

void handle_usr1(int signum)
{
	signal(SIGUSR1, handle_usr1);
	signal(SIGUSR2, handle_usr2);
	bit <<= 1;
	usleep(100000);
	a = 1;
}

void handle_usr2(int signum)
{
	signal(SIGUSR1, handle_usr1);
	signal(SIGUSR2, handle_usr2);
	bit = (bit << 1) | 1;
	usleep(100000);
	a = 1;
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, handle_usr1);
	signal(SIGUSR2, handle_usr2);
	printf("%d\n", getpid());
	while (1)
	{
		if (a == 1)
		{
			printf("%c", bit);
			bit = 0;
			a = 0;
		}
		printf("...\n");
		sleep(3);
	}
}
