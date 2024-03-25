/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:00:40 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/25 02:58:15 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pull_chunk(t_object *obj, int *size)
{
	int			target;
	int			tmp;
	int			moves;
	t_list		*h;

	target = obj->stack_a->index - 1;
	if (obj->stack_b->index == target
		|| ft_lstlast(obj->stack_b)->index == target)
	{
		if (obj->stack_b->index != target)
			reverse_rotate(NULL, &obj->stack_b);
		push(&obj->stack_b, &obj->stack_a, "pa");
		*size -= 1;
	}
	else
	{
		tmp = *size / 2;
		while (tmp)
		{
			if (obj->stack_b->index == target)
			{
				
			}
		}
	}

}

int	push_chunk(t_object *obj, int s)
{
	static int	i;
	static int	pushed;

	if (obj->stack_a->index <= s + pushed)
	{
		push(&obj->stack_a, &obj->stack_b, "pb");
		if (obj->stack_b->index <= pushed + (s / 2))
			rotate(NULL, &obj->stack_b);
		i++;
	}
	else
		rotate(&obj->stack_a, NULL);
	if (i == s)
	{
		pushed += i;
		i = 0;
		return (s);
	}
	return (0);
}

void	sort(t_object *obj)
{
	int		size;
	int		tmp;

	size = is_sorted(obj->stack_a);
	if (!size)
		return ;
	tmp = size;
	while (size > 3)
		size -= push_chunk(obj, size / 3);
	sort_three(obj);
	size = tmp - 3;
	while (obj->stack_b)
		pull_chunk(obj, &size);
}
