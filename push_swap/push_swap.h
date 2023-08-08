/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:32:21 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/08 21:37:35 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./operations/operations.h"

void	check_error(void);

//libft functions
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *a);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

//sorting functions
void	start_sorting(t_num_node **a, t_num_node **b);
void	print_node(t_num_node **a);
#endif
