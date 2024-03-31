/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:09:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 14:32:12 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*item;
	t_list	*last;

	if (stack && *stack)
	{
		item = (*stack)->next;
		if (!item)
			return ;
		last = ft_lstlast(*stack);
		(*stack)->next = NULL;
		last->next = *stack;
		*stack = item;
	}
}

void	ra(t_object *obj)
{
	rotate(&obj->stack_a.list);
}

void	rb(t_object *obj)
{
	rotate(&obj->stack_b.list);
}

void	rr(t_object *obj)
{
	rotate(&obj->stack_a.list);
	rotate(&obj->stack_b.list);
}
