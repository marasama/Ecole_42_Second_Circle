/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:08:13 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/20 00:21:28 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./ft_printf/ft_printf.h"
# include "./operations/operations.h"
# include "./libft/libft.h"

//check functions
int		atoi_check(char *s);
int		check_int(char **a, int b);
int		check_sort(t_num_node **a);
int		check_rpt(t_num_node **a);

//helper functions
void	start_operations(t_num_node **a);
char	*take_operations(void);
void	swap_opr(t_num_node **a, t_num_node **b, char *operation);
void	push_opr(t_num_node **a, t_num_node **b, char *operation);
void	rotate_opr(t_num_node **a, t_num_node **b, char *operation);
void	free_array(char **a, int b);

#endif
