/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:31:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/19 05:43:43 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_error(t_num_node **a, char **b, int option, int c)
{
	if (a != NULL)
		free_node(a, 2);
	if (option == 1 || option == 2)
		free_array(b, c);
	if (option == 2)
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
	if (!check_int(argv) || argc == 1)
		check_error(NULL, argv, argc, c);
	while (--argc > c)
		node_maker(&a, ft_atoi(argv[argc]), 0);
	if (check_rpt(&a))
		check_error(&a, argv, 2, c);
	if (check_sort(&a))
		return (0);
	place_node_order(&a);
	select_sorts(&a, node_count(&a));
	free_node(&a, 2);
	free_array(argv, c);
}
