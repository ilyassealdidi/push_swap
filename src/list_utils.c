/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:26:25 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/29 23:14:35 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstshift_down(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (ft_lstsize(*lst) <= 1)
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
