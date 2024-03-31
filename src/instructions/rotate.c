/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:09:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 20:06:57 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	rotate(t_list **list)
{
	t_list	*item;
	t_list	*last;

	if (!list || ft_lstsize(*list) <= 1)
		return (0);
	item = (*list)->next;
	last = ft_lstlast(*list);
	(*list)->next = NULL;
	last->next = *list;
	*list = item;
	return (1);
}

void	ra(t_object *obj)
{
	if (rotate(&obj->stack_a.list))
		ft_printf("%s\n", "ra");
}

void	rb(t_object *obj)
{
	if (rotate(&obj->stack_b.list))
		ft_printf("%s\n", "rb");
}

void	rr(t_object *obj)
{
	if (rotate(&obj->stack_a.list) || rotate(&obj->stack_b.list))
		ft_printf("%s\n", "rr");
}
