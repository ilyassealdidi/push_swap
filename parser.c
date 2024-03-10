/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:46:04 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/10 10:34:11 by ialdidi          ###   ########.fr       */
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

t_list	*extract_numbers(char **args)
{
	char	**nums;
	long	*number;
	t_list	*head;

	head = NULL;
	while (*args)
	{
		nums = ft_split(*args++, ' ');
		if (!nums)
			exiter();
		while (*nums)
		{
			number = get_number(*nums++);
			if (!number || !ft_lstappenditem(&head, number))
				exiter();
		}
	}
	return (head);
}
