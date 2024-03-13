/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:46:04 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/13 15:49:34 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*get_number(char *num)
{
	long	*number;
	char	*ptr;

	if (ft_strspn(num, "-+0123456789") != ft_strlen(num))
		return (NULL);
	ptr = ft_strpbrk(num, "-+");
	if (ptr && ft_strpbrk(++ptr, "-+"))
		return (NULL);
	ptr = ft_strpbrk(num, "0123456789");
	if (!ptr || (ptr && ft_strpbrk(++ptr, "-+")))
		return (NULL);
	number = (long *)malloc(sizeof(long));
	if (!number)
		return (NULL);
	*number = ft_atol(num);
	if (*number < INT_MIN || *number > INT_MAX)
		return (free(number), NULL);
	return (number);
}

t_list	*extract_numbers(char **strs)
{
	char	**nums;
	long	*number;
	t_list	*head;
	int		i;

	head = NULL;
	while (*strs)
	{
		i = -1;
		nums = ft_split(*strs++, ' ');
		if (!nums || !nums[0])
			return (ft_lstclear(&head, free), free_memory(nums), NULL);
		while (nums[++i])
		{
			number = get_number(nums[i]);
			if (!number || !ft_lstappenditem(&head, number))
				return (free(number), ft_lstclear(&head, free),
					free_memory(nums), NULL);
		}
		free_memory(nums);
	}
	return (head);
}

void	list_init(t_object *obj, char **strs)
{
	obj->stack_a = extract_numbers(strs);
	if (!obj->stack_a)
		exiter();
}
