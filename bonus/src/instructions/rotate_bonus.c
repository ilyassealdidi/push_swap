/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:09:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 20:11:36 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	rotate(t_list **list)
{
	t_list	*item;
	t_list	*last;

	if (!list || ft_lstsize(*list) <= 1)
		return ;
	item = (*list)->next;
	last = ft_lstlast(*list);
	(*list)->next = NULL;
	last->next = *list;
	*list = item;
}

void	ra(t_object *obj)
{
	rotate(&obj->stack_a.list);
}

void	rb(t_object *obj)
{
	rotate(&obj->stack_b.list);
}

void	rr(t_object *obj)
{
	rotate(&obj->stack_a.list);
	rotate(&obj->stack_b.list);
}
