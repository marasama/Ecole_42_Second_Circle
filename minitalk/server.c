#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	ft_intlen(int a)
{
	int	b;

	b = 0;
	if (a == -2147483648)
		return (11);
	if (a < 0)
	{
		a = -a;
		b++;
	}
	while ((a / 10) != 0)
	{
		a /= 10;
		b++;
	}
	return (b + 1);
}

void	ft_inttostr(char *a, int b, int c, int n)
{
	if (n < 0)
	{
		b = 1;
		a[0] = '-';
		if (n == -2147483648)
		{
			a[c--] = '8';
			n = -214748364;
		}
		n = -n;
	}
	while (c >= b)
	{
		a[c] = (n % 10) + 48;
		n /= 10;
		c--;
	}
}

char	*ft_itoa(int n)
{
	char	*a;
	int		b;
	int		c;
	int		d;

	b = 0;
	c = ft_intlen(n);
	d = ft_intlen(n);
	a = (char *)malloc(sizeof(char) * (c + 1));
	if (a == 0)
		return (NULL);
	c--;
	ft_inttostr(a, b, c, n);
	a[d] = '\0';
	return (a);
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
	ft_putstr(ft_itoa(getpid()));
	while (1)
	{
		pause();
	}
	return (0);
}
