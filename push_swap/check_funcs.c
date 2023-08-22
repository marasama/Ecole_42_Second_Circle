/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:02:16 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/22 18:47:32 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	atoi_check(char *s)
{
	int		b;

	b = 0;
	if (s[b] == '-' || s[b] == '+')
		b++;
	while (s[b] < 58 && s[b] > 47)
		b++;
	if (b == 1 && (s[b] == '+' || s[b] == '-'))
		return (0);
	return (b);
}

int	check_int(char **a, int b)
{
	int		c;
	int		d;

	if (a[++b] == '\0')
		return (0);
	b--;
	while (a[++b])
	{
		if (a[b][0] == '\0')
			return (0);
		c = ft_strlen(a[b]);
		d = atoi_check(a[b]);
		if (c != d || d > 11)
			return (0);
		if (ft_atoi(a[b]) < -2147483648 || ft_atoi(a[b]) > 2147483647)
			return (0);
	}
	return (1);
}

int	check_sort(t_num_node **a)
{
	t_num_node	*b;

	b = *a;
	if ((b->next) == NULL)
		return (1);
	else if (b->num < b->next->num)
	{
		b = b->next;
		return (check_sort(&b));
	}
	else
		return (0);
}

int	check_rpt(t_num_node **a)
{
	t_num_node	*first;
	t_num_node	*second;

	first = *a;
	while (first->next != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			if (second->num == first->num)
				return (1);
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}
