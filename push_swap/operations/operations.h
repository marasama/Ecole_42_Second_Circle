/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:55:43 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/07 06:10:01 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../ft_printf/ft_printf.h"

typedef struct t_num_node
{
	int					num;
	struct t_num_node	*prev;
	struct t_num_node	*next;
}t_num_node;

//node functions
void	node_maker(t_num_node **a, int b);
void	free_node(t_num_node **a, int b);
//operation functions
void	sa(t_num_node **a);
void	sb(t_num_node **b);
void	ss(t_num_node **a, t_num_node **b);
void	pa(t_num_node **a, t_num_node **b);
void	pb(t_num_node **a, t_num_node **b);
void	ra(t_num_node **a);
void	rb(t_num_node **b);
void	rr(t_num_node **a, t_num_node **b);
void	rra(t_num_node **a);
void	rrb(t_num_node **b);
void	rrr(t_num_node **a, t_num_node **b);

#endif
