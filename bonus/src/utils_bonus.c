/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:29:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/02 18:37:48 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

int	get_item_index(t_list *node)
{
	return (((t_item *)node->content)->index);
}

void	destroy_object(t_object *obj)
{
	ft_lstclear(&obj->stack_a.list, free);
	ft_lstclear(&obj->stack_b.list, free);
	ft_lstclear(&obj->instructions, free);
}
