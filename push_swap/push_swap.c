/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:31:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 05:32:59 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	atoi_check(char *s)
{
	int		b;

	b = 0;
	while (s[b] == 32)
		b++;
	if (s[b] == '-' || s[b] == '+')
		b++;
	while (s[b] < 58 && s[b] > 47)
		b++;
	return (b);
}

int	check_int(char **a)
{
	int		b;
	int		c;
	int		d;

	b = 1;
	while (a[b])
	{
		c = ft_strlen(a[b]);
		d = atoi_check(a[b]);
		if (c != d)
			return (0);
		if (a[b][0] != '+' && a[b][0] != '-' && c > 11)
			return (0);
		if (a[b][0] == '+' && d == 11)
			if (ft_strncmp(a[b], "+2147483647", d) < 0)
				return (0);
		if ((a[b][0] == '-' && d == 11))
			if (ft_strncmp(a[b], "-2147483648", d) < 0)
				return (0);
		if (a[b][0] != '+' && a[b][0] != '-' && d == 10)
			if (ft_strncmp(a[b], "2147483647", d) < 0)
				return (0);
		b++;
	}
	return (1);
}

int	check_sort_rpt(t_num_node *a)
{
	t_num_node	*first;
	t_num_node	*second;
	int			b;

	first = a;
	b = first->num;
	while (first->next != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			if (second->num <= b || second->num == b)
				return (1);
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			c;
	t_num_node	*a;
	t_num_node	*b;

	if (argc == 1)
		check_error();
	a = NULL;
	b = NULL;
	if (!check_int(argv))
		check_error();
	c = 1;
	while (argv[c])
		node_maker(&a, ft_atoi(argv[c++]));
	if (check_sort_rpt(a))
	{
		free_node(&a, 2);
		check_error();
	}
	start_sorting(&a, &b);
	return (0);
}
