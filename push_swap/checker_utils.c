/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:13:07 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/20 00:19:43 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	start_operations(t_num_node **a)
{
	t_num_node	*b;
	char		**operations;
	int			i;

	b = NULL;
	operations = ft_split(take_operations(), '\n');
	i = 0;
	while (operations[i])
	{
		if (operations[i][0] == 's')
			swap_opr(a, &b, operations[i]);
		if (operations[i][0] == 'p')
			push_opr(a, &b, operations[i]);
		if (operations[i][0] == 'r')
			rotate_opr(a, &b, operations[i]);
		i++;
	}
	if (check_sort(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_array(operations, -1);
}

char	*take_operations(void)
{
	char	*cake;
	int		check;
	char	*wholecake;

	wholecake = ft_calloc(1, 1);
	cake = ft_calloc(11, sizeof(char));
	check = 1;
	while (check > 0)
	{
		check = read(0, cake, 10);
		if (check == -1)
		{
			free(cake);
			return (NULL);
		}
		cake[check] = '\0';
		wholecake = ft_strjoin(wholecake, cake);
	}
	free(cake);
	return (wholecake);
}

void	swap_opr(t_num_node **a, t_num_node **b, char *operation)
{
	if (operation[1] == 's')
	{
		sa(a, 0);
		sb(b, 0);
	}
	else if (operation[1] == 'b')
		sb(b, 0);
	else if (operation[1] == 'a')
		sa(b, 0);
}

void	push_opr(t_num_node **a, t_num_node **b, char *operation)
{
	if (operation[1] == 'a')
		pa(a, b, 0);
	else if (operation[1] == 'b')
		pb(a, b, 0);
}

void	rotate_opr(t_num_node **a, t_num_node **b, char *operation)
{
	if (operation[1] == 'a')
		ra(a, 0);
	else if (operation[1] == 'b')
		rb(a, 0);
	else if (operation[1] == 'r')
	{
		if (operation[2] == '\0')
			rr(a, b, 0);
		else if (operation[2] == 'b')
			rrb(b, 0);
		else if (operation[2] == 'a')
			rra(a, 0);
		else if (operation[2] == 'r')
			rrr(a, b, 0);
	}
}
