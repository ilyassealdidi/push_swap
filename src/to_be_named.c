/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_be_named.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:04:00 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/25 02:31:23 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *lst)
{
	int	num;
	int	is_sorted;

	is_sorted = 1;
	num = 0;
	while (lst)
	{
		if (lst->index < num)
			is_sorted = 0;
		num++;
		lst = lst->next;
	}
	return (num * (is_sorted == 0));
}

void	sort_five(t_object *obj)
{
	
}

void	sort_three(t_object *obj)
{
	if (is_sorted(obj->stack_a))
		return ;
	if (obj->stack_a->index < obj->stack_a->next->index)
		reverse_rotate(&obj->stack_a, NULL);
	else if (obj->stack_a->index > obj->stack_a->next->index
		&& obj->stack_a->index > obj->stack_a->next->next->index)
		rotate(&obj->stack_a, NULL);
	if (obj->stack_a->index > obj->stack_a->next->index)
		swap(&obj->stack_a, NULL);
}
