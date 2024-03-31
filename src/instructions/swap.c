/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:13:23 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 20:03:21 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	swap(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (!lst || ft_lstsize(*lst) <= 1)
		return (0);
	tmp = (*lst)->next;
	item = tmp->next;
	(*lst)->next = item;
	tmp->next = *lst;
	*lst = tmp;
	return (1);
}

void	sa(t_object *obj)
{
	if (swap(&obj->stack_a.list))
		ft_printf("%s\n", "sa");
}

void	sb(t_object *obj)
{
	if (swap(&obj->stack_b.list))
		ft_printf("%s\n", "sb");
}

void	ss(t_object *obj)
{
	if (swap(&obj->stack_a.list) || swap(&obj->stack_b.list))
		ft_printf("%s\n", "ss");
}
