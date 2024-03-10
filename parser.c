/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:46:04 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/10 15:29:07 by ialdidi          ###   ########.fr       */
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
		if (!nums)
			return (NULL);
		if (!nums[0])
			return (ft_lstclear(&head, free), free_memory(nums), NULL);
		while (nums[++i])
		{
			number = get_number(nums[i]);
			if (!number || !ft_lstappenditem(&head, number))
				return (free(number), free_memory(nums), ft_lstclear(&head, free), NULL);
		}
		free_memory(nums);
	}
	return (head);
}

int	parse(t_object *obj, char **strs)
{
	t_list	*list;

	list = extract_numbers(strs);
	if (!list)
		return (0);
	obj->numbers = list;
	return (1);
}
