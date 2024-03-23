/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:00:40 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/23 18:07:24 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pull_chunk(t_object *obj, int s)
{
	static int	cnt;
	static int	chunk_size;

	if (chunk_size == 0)
		return (chunk_size = s / 3, (void)0);
	if (obj->stack_b->index == s - cnt)
	{
		push(&obj->stack_b, &obj->stack_a, "pa");
		chunk_size--;
		cnt++;
	}
	else
	{
		if (s - obj->stack_a->index < s / 3)
			rotate(NULL, &obj->stack_b);
		else
			reverse_rotate(NULL, &obj->stack_b);
	}
}

int	push_chunk(t_object *obj, int s)
{
	static int	i;
	static int	tmp = 1;

	if (obj->stack_a->index <= tmp * s / 3)
	{
		push(&obj->stack_a, &obj->stack_b, "pb");
		if (i % 2)
			rotate(NULL, &obj->stack_b);
		i++;
	}
	else if (i == tmp * s / 3)
		tmp++;
	else
		rotate(&obj->stack_a, NULL);
	return (tmp);
}

void	sort(t_object *obj)
{
	int			stack_size;

	while (obj->stack_a)
	{
		stack_size = ft_lstsize(obj->stack_a);
		push_chunk(obj, stack_size);
	}
	// while (obj->stack_b)
	// {
	// 	pull_chunk(obj, stack_size);
	// }
}
