/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:09 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 01:17:50 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	initial_or_second_part(t_stack stack, int target)
{
	t_list	*list;
	int		size;

	list = stack.list;
	size = stack.length / 2;
	while (size--)
	{
		if (get_item_index(list) == target)
			return (1);
		list = list->next;
	}
	return (2);
}

int	is_sorted(t_list *lst)
{
	int		tmp;

	tmp = 0;
	while (lst)
	{
		if (get_item_index(lst) < tmp)
			return (0);
		tmp = get_item_index(lst);
		lst = lst->next;
	}
	return (1);
}

int	get_first_index(t_stack stack)
{
	return (((t_item *)stack.list->content)->index);
}

int	get_last_index(t_stack stack)
{
	return (((t_item *)ft_lstlast(stack.list)->content)->index);
}

int	get_item_index(t_list *node)
{
	return (((t_item *)node->content)->index);
}
