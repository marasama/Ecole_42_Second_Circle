/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:31:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/12 00:24:11 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(t_num_node **a)
{
	if (a != NULL)
		free_node(a, 2);
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

int	main(int argc, char **argv)
{
	t_num_node	*a;
	int			c;

	a = NULL;
	c = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		c = -1;
	}
	argc--;
	if (!check_int(argv))
		check_error(NULL);
	while (argc > c)
		node_maker(&a, ft_atoi(argv[argc--]), 0);
	if (check_rpt(&a) || check_sort(&a))
		check_error(&a);
	place_node_order(&a);
	start_sorting(&a);
}
