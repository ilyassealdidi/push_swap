/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:19:56 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 20:09:50 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	reverse_rotate(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (!lst || ft_lstsize(*lst) <= 1)
		return (0);
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
	return (1);
}

void	rra(t_object *obj)
{
	if (reverse_rotate(&obj->stack_a.list))
		ft_printf("rra\n");
}

void	rrb(t_object *obj)
{
	if (reverse_rotate(&obj->stack_b.list))
		ft_printf("rrb\n");
}

void	rrr(t_object *obj)
{
	if (reverse_rotate(&obj->stack_a.list) 
		+ reverse_rotate(&obj->stack_b.list))
		ft_printf("rrr\n");
}
