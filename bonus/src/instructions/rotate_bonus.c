/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:09:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/02 18:33:26 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	rotate(t_list **lst)
{
	t_list	*item;
	t_list	*last;

	if (!*lst || !(*lst)->next)
		return ;
	item = (*lst)->next;
	last = ft_lstlast(*lst);
	(*lst)->next = NULL;
	last->next = *lst;
	*lst = item;
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
