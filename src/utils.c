/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:09 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/28 21:09:36 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	initial_or_second_part(t_list *lst, int target, int size)
{
	while (size--)
	{
		if (lst->index == target)
		{
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int	is_sorted(t_list *lst)
{
	int	num;
	int	is_sorted;

	is_sorted = 1;
	num = 0;
	while (lst)
	{
		if (lst->next && lst->index > lst->next->index)
			is_sorted = 0;
		num++;
		lst = lst->next;
	}
	return (num * (is_sorted == 0));
}

void	sort_five(t_object *obj)
{
	if (is_sorted(obj->stack_a) == 0)
		return ;
	while (ft_lstsize(obj->stack_a) != 3)
	{
		if ()
	}
	sort_three(obj);
}



void	exiter(void)
{
	ft_printf("Error\n");
	exit(1);
}
