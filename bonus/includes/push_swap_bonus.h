/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:30:57 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/02 18:38:11 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../libs/libft/libft.h"

typedef struct s_item
{
	int			data;
	int			index;
}	t_item;

typedef struct s_stack
{
	t_list		*list;
	int			length;
}	t_stack;

typedef struct s_object
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_list		*instructions;
	int			max;
}	t_object;

/*		Parsing				*/
int		stack_init(t_object *obj, char **strs);

/*		Instructions		*/
void	pa(t_object *obj);
void	pb(t_object *obj);
void	sa(t_object *obj);
void	sb(t_object *obj);
void	ss(t_object *obj);
void	ra(t_object *obj);
void	rb(t_object *obj);
void	rr(t_object *obj);
void	rra(t_object *obj);
void	rrb(t_object *obj);
void	rrr(t_object *obj);

/*		Checker				*/
int		check_sort(t_object *obj);

/*		Utilities			*/
void	destroy_object(t_object *obj);
int		is_sorted(t_list *lst);
int		get_item_index(t_list *node);

#endif
