/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:51:41 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 16:43:57 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
