/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/09 15:35:39 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	exiter()
{
	ft_printf("Error\n");
	exit(0);
}
// "  23  "
// 
int	*get_number(char *num)
{
	int		*number;
	char	*sign;
	int		i;

	if (ft_strspn(num, " -+0123456789") != ft_strlen(num))
		return (NULL);
	sign = ft_strpbrk(num, "-+");
	if (sign && ft_strpbrk(++sign, "-+"))
		return (NULL);
	number = (int *)malloc(sizeof(int));
	if (!number)
		return (NULL);
	*number = ft_atoi(num);
	return (number);
}

t_list	*extract_numbers(char **args)
{
	char	**nums;
	int		*number;
	t_list	*head;
	t_list	*item;

	head = NULL;
	while (*args)
	{
		nums = ft_split(*args, ' ');
		if (!nums)
			exiter();
		while (*nums)
		{
			number = get_number(*nums++);
			if (!number)
				exiter();
			item = ft_lstnew(number);
			if (!head)
				head = item;
			else
				ft_lstadd_back(&head, item);
		}
		args++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*list;
	if (ac >= 2)
	{
		list = extract_numbers(av + 1);
		if (!list)
			return (EXIT_FAILURE);
		while (list)
		{
			ft_printf("%d\n", *(int *)(list->content));
			list = list->next;
		}
	}
	return (EXIT_SUCCESS);
}