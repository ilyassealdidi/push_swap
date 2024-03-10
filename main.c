/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/10 12:10:52 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	exiter()
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int ac, char **av)
{
	// t_object	obj;
	t_list		*item;

	item = NULL;
	if (ac >= 2)
	{
		item = extract_numbers(av + 1);
		if (!item)
			return (EXIT_FAILURE);
		while (item)
		{
			ft_printf("%d\n", *(int *)(item->content));
			item = item->next;
		}
	}
	else
		ft_printf("Invalid number of arguments");
	return (EXIT_SUCCESS);
}
