/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:19:56 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 22:04:23 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (!lst || !(*lst)->next)
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
	ft_printf("rra\n");
}

void	rrb(t_object *obj)
{
	reverse_rotate(&obj->stack_b.list);
	ft_printf("rrb\n");
}

void	rrr(t_object *obj)
{
	reverse_rotate(&obj->stack_a.list);
	reverse_rotate(&obj->stack_b.list);
	ft_printf("rrr\n");
}
