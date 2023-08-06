/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:32:21 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 02:00:10 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

typedef struct t_num_node
{
	int			num;
	t_num_node	*prev;
	t_num_node	*next;
}t_num_node;

//libft
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *a);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

//node functions
void	node_maker(t_num_node **a, int b);
void	free_node(t_num_node **a, int b);

#endif
