/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:32:21 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/20 00:09:49 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./operations/operations.h"
# include "./libft/libft.h"

//check functions
int		atoi_check(char *s);
int		check_int(char **a, int b);
int		check_sort(t_num_node **a);
int		check_rpt(t_num_node **a);

//sorting functions
void	select_sorts(t_num_node **a, int node_size);
void	start_sorting(t_num_node **a);
void	triple_sort(t_num_node **a);
void	quadra_sort(t_num_node **a);

//cost calculation functions
int		get_min_max_order(t_num_node **b, int option);
int		min_max_cost_calc(t_num_node **a, int order);
int		get_place_cost(t_num_node **b, int order);
int		cost_a(t_num_node **a, int order);
int		cost_b(t_num_node **b, int order);
int		cost_calculator(t_num_node **a, t_num_node **b, int option);

#endif
