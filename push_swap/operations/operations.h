/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 04:55:43 by adurusoy          #+#    #+#             */
/*   Updated: 2023/08/18 19:51:25 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../ft_printf/ft_printf.h"

typedef struct s_num_node
{
	int					num;
	int					correct_order;
	struct s_num_node	*prev;
	struct s_num_node	*next;
}t_num_node;

//node functions
void		node_maker(t_num_node **a, int b, int d);
void		free_node(t_num_node **a, int b);
int			node_count(t_num_node **a);
int			find_min_node(t_num_node **a);
t_num_node	*get_last_node(t_num_node **b);

//operation functions
void		sa(t_num_node **a);
void		sb(t_num_node **b);
void		ss(t_num_node **a, t_num_node **b);
void		pa(t_num_node **a, t_num_node **b);
void		pb(t_num_node **a, t_num_node **b);
void		r_node(t_num_node **a);
void		ra(t_num_node **a);
void		rb(t_num_node **b);
void		rr(t_num_node **a, t_num_node **b);
void		r_rev(t_num_node **a);
void		rra(t_num_node **a);
void		rrb(t_num_node **b);
void		rrr(t_num_node **a, t_num_node **b);

#endif
