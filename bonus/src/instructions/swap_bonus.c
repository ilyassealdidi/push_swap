/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:13:23 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/02 17:21:17 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	swap(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	item = tmp->next;
	(*lst)->next = item;
	tmp->next = *lst;
	*lst = tmp;
}

void	sa(t_object *obj)
{
	swap(&obj->stack_a.list);
}

void	sb(t_object *obj)
{
	swap(&obj->stack_b.list);
}

void	ss(t_object *obj)
{
	swap(&obj->stack_a.list);
	swap(&obj->stack_b.list);
}
