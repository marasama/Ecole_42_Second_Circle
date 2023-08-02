#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

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

void	ft_putstr(char *s)
{
	int		a;

	if (s == NULL)
	{
		return ;
	}
	a = 0;
	while (s[a] != 0)
	{
		write(1, &s[a++], 1);
	}
}


void	handle_sigusr(int signum)
{
	ft_putstr("Received!\n");
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

	b = 20;
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
	int pid = ft_atoi(argv[1]);
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
