/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:09 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 00:16:46 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	initial_or_second_part(t_list *lst, int target, int size)
// {
// 	t_item	*item;

// 	while (size--)
// 	{
// 		item = (t_item *)lst->content;
// 		if (item->index == target)
// 			return (1);
// 		lst = lst->next;
// 	}
// 	return (2);
// }

// int	is_sorted(t_list *lst)
// {
// 	int		num;
// 	int		is_sorted;

// 	is_sorted = 1;
// 	num = 0;
// 	while (lst)
// 	{
// 		if (lst->next
// 			&& ((t_item *)lst->content)->index > ((t_item *)lst->next->content)->index)
// 			is_sorted = 0;
// 		num++;
// 		lst = lst->next;
// 	}
// 	return (num * (is_sorted == 0));
// }

// void	sort_five(t_object *obj)
// {
// 	int	min;

// 	min = ((obj->max > 5) * (obj->max - ft_lstsize(obj->stack_a))) + 1;
// 	while (ft_lstsize(obj->stack_a) != 3)
// 	{
// 		if (is_sorted(obj->stack_a) == 0)
// 			return ;
// 		if (obj->stack_a->index == min)
// 		{
// 			push(&obj->stack_a, &obj->stack_b, "pb");
// 			min++;
// 		}
// 		else if (initial_or_second_part(obj->stack_a, min, 5 / 2) == 1
// 			|| obj->stack_a->next->index == min)
// 			rotate(&obj->stack_a, NULL);
// 		else
// 			reverse_rotate(&obj->stack_a, NULL);
// 	}
// 	sort_three(obj);
// }

void	free_array(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (1)
	{
		free(strs[++i]);
		if (!strs[i])
			break ;
	}
	free(strs);
}


void	exiter(void)
{
	ft_printf("Error\n");
	exit(1);
}
