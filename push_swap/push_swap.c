/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:31:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/09 22:18:53 by adurusoy         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_num_node	*a;
	t_num_node	*b;
	int			c;

	a = NULL;
	b = NULL;
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
		node_maker(&a, ft_atoi(argv[argc--]));
	if (check_rpt(&a) || check_sort(&a))
		check_error(&a);
	start_sorting(&a, &b);
}
