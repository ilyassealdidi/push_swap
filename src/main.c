/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/05 03:19:17 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_object	obj;

	if (ac < 2)
		return (0);
	ft_memset(&obj, 0, sizeof(obj));
	if (!stack_init(&obj, av + 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort(&obj);
	ft_lstclear(&obj.stack_a.list, free);
	return (0);
}
