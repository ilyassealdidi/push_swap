/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:46:04 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 12:34:03 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	free_array(char **strs)
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

static long	get_number(char *num)
{
	char	*ptr;

	if (ft_strspn(num, "-+0123456789") != ft_strlen(num))
		return (LONG_MAX);
	ptr = ft_strpbrk(num, "-+");
	if (ptr && ft_strpbrk(++ptr, "-+"))
		return (LONG_MAX);
	ptr = ft_strpbrk(num, "0123456789");
	if (!ptr || (ptr && ft_strpbrk(++ptr, "-+")))
		return (LONG_MAX);
	return (ft_atol(num));
}

static int	set_index(t_list *list, t_item *new)
{
	t_item	*node;

	while (list)
	{
		node = (t_item *)list->content;
		if (new->data > node->data)
			new->index++;
		else if (new->data < node->data)
			node->index++;
		else
			return (0);
		list = list->next;
	}

	return (1);
}

static int	insert_number(t_list **lst, int number)
{
	t_item	*item;
	t_list	*node;

	item = (t_item *)malloc(sizeof(t_item));
	if (!item)
		return (0);
	item->data = number;
	item->index = 1;
	node = ft_lstnew(item);
	if (!node)
		return (free(item), 0);
	if (!set_index(*lst, item))
		return (free(node), free(item), 0);
	if (!lst)
		*lst = node;
	else
		return (ft_lstadd_back(lst, node), 1);
	return (free(item), 0);
}

int	stack_init(t_object *obj, char **strs)
{
	t_stack	*stack;
	char	**nums;
	int		number;
	int		i;

	stack = &obj->stack_a;
	while (*strs)
	{
		i = -1;
		nums = ft_split(*strs++, ' ');
		if (!nums || !nums[0])
			return (ft_lstclear(&stack->list, free), free_array(nums), 0);
		while (nums[++i])
		{
			number = get_number(nums[i]);
			if (number < INT_MIN || number > INT_MAX
				|| !insert_number(&stack->list, number))
				return (ft_lstclear(&stack->list, free), free_array(nums), 0);
			stack->length++;
		}
		free_array(nums);
	}
	obj->max = obj->stack_a.length;
	return (1);
}
