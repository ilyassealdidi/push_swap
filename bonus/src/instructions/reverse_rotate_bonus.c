/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:19:56 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 20:10:32 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (!lst || ft_lstsize(*lst) <= 1)
		return ;
	item = *lst;
	while (item)
	{
		if (!item->next->next)
		{
			tmp = item->next;
			item->next = NULL;
		}
		item = item->next;
	}
	tmp->next = *lst;
	*lst = tmp;
}

void	rra(t_object *obj)
{
	reverse_rotate(&obj->stack_a.list);
}

void	rrb(t_object *obj)
{
	reverse_rotate(&obj->stack_b.list);
}

void	rrr(t_object *obj)
{
	reverse_rotate(&obj->stack_a.list);
	reverse_rotate(&obj->stack_b.list);
}
