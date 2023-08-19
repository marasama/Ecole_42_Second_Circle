/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:07:47 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/20 00:22:38 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_array(char **a, int b)
{
	int	i;

	i = 0;
	if (b == -1)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
}

void	check_error(t_num_node **a, char **b, int c, int d)
{
	if (a != NULL)
		free_node(a, 2);
	if (c == -1)
		free_array(b, c);
	if (d == 2)
		ft_printf("Error\n");
	exit(1);
}

void	place_node_order(t_num_node **a)
{
	t_num_node	*b;
	int			c;
	int			d;
	int			e;

	d = node_count(a);
	e = 1;
	while (e <= d)
	{
		b = *a;
		c = find_min_node(a);
		while (b != NULL)
		{
			if (b->num == c)
				b->correct_order = e;
			b = b->next;
		}
		e++;
	}
}

char	**split_args(char *a, int *b, int *c)
{
	char	**d;

	d = ft_split(a, ' ');
	(*b) = 0;
	while (d[(*b)])
		(*b)++;
	(*c) = -1;
	return (d);
}

int	main(int argc, char **argv)
{
	t_num_node	*a;
	int			c;

	a = NULL;
	c = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		argv = split_args(argv[1], &argc, &c);
	if (!check_int(argv, c))
		check_error(NULL, argv, c, 2);
	while (--argc > c)
		node_maker(&a, ft_atoi(argv[argc]), 0);
	if (check_rpt(&a))
		check_error(&a, argv, c, 2);
	if (check_sort(&a))
		return (0);
	place_node_order(&a);
	start_operations(&a);
	free_node(&a, 2);
	free_array(argv, c);
}
