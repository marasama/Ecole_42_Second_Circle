/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:31:46 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/06 22:18:49 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char **a)
{
	return (1);
}

void	node_maker(t_num_node **a, int b)
{
	t_num_node *c = (t_num_node *)malloc(sizeof(t_num_node));
	c->num = b;
	c->next = *a;
	if (*a != NULL)
		
	*a = c;
}

int	main(int argc, char **argv)
{
	int			a;
	t_num_node	*b = NULL;

	if (!check_int(argv))
	{
		ft_printf("Error\n");
		return (-1);
	}
	a = 1;
	argv = convert_int(argv);
	while (argv[a])
		argv = ft_split(argv[1], ' ');
	if (check_sort(argv) || check_rpt(argc))
		return (0);
}
