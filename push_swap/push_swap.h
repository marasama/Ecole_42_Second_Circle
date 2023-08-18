/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:32:21 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/18 22:48:10 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./operations/operations.h"

//check functions
int		atoi_check(char *s);
int		check_int(char **a);
int		check_sort(t_num_node **a);
int		check_rpt(t_num_node **a);

//libft functions
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *a);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_abs(int a);

//sorting functions
void	start_sorting(t_num_node **a);
void	simple_sorts(t_num_node **a);
void	triple_sort(t_num_node **a);

//cost calculation functions
int		get_min_max_order(t_num_node **b, int option);
int		min_max_cost_calc(t_num_node **a, int order);
int		get_place_cost(t_num_node **b, int order);
int		cost_a(t_num_node **a, int order);
int		cost_b(t_num_node **b, int order);
int		ret_calc(int total_cost, int cost_a, int cost_b, int option);
int		cost_calculator(t_num_node **a, t_num_node **b, int option);

#endif
