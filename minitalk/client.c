#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void	handle_sigusr(int signum)
{
	printf("Arrived!\n");
}

int checkbit(int a, int b)
{
	int c = 1 << b;
	int check = a & c;
	if (check == 0)
		return 0;
	else
		return (1);
}

void sendnumber(int a, int pid)
{
	int b;

	b = 31;
	while (b >= 0)
	{
		if (checkbit(a, b) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		b--;
	}
}

int main(int argc, char **argv)
{
	int pid = atoi(argv[1]);
	int c = 0;
	signal(SIGUSR1, handle_sigusr);
	sendnumber(getpid(), pid);
	while (argv[2][c])
	{
		sendnumber((int)argv[2][c], pid);
		usleep(1000);
		c++;
	}
}
