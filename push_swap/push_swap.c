/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:31:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 02:18:11 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if ((ft_strncmp(a[b], "+2147483647"), d) < 0)
				return (0);
		if ((a[b][0] == '-' && d == 11))
			if ((ft_strncmp(a[b], "-2147483648"), d) < 0)
				return (0);
		if (a[b][0] != '+' && a[b][0] != '-' && d == 10)
			if ((ft_strncmp(a[b], "2147483647"), d) < 0)
				return (0);
		b++;
	}
	return (1);
}

int	check_sort_rpt(t_num_node *a)
{
	t_num_node	*tmp;
	int			b;

	tmp = a;
	b = tmp->num;
	while (tmp->next != NULL)
	{
		if (a->num)
	}
}

int	main(int argc, char **argv)
{
	int			a;
	t_num_node	*b;

	b = NULL;
	if (!check_int(argv))
	{
		ft_printf("Error\n");
		return (-1);
	}
	a = 1;
	while(argv[a])
		node_maker(&b, ft_atoi(argv[a++]));
	if (check_sort_rpt(b))
	{
		free_node(&b, 2);
		ft_printf("Error\n");
		return (-1);
	}

}
