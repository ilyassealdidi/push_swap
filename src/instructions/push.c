/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:26:29 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 14:36:49 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack *stack_from, t_stack *stack_to, char *instruction)
{
	t_list	*tmp;

	if (!stack_from->list)
		return ;
	tmp = stack_from->list->next;
	stack_from->list->next = NULL;
	ft_lstadd_front(&stack_to->list, stack_from->list);
	stack_from->list = tmp;
	stack_from->length--;
	stack_to->length++;
	ft_printf("%s\n", instruction);
}

void	pa(t_object *obj)
{
	push(&obj->stack_b, &obj->stack_a, "pa");
}

void	pb(t_object *obj)
{
	push(&obj->stack_a, &obj->stack_b, "pb");
}
