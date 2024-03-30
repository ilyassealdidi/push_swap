/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:09 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 14:54:49 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	is_sorted(t_list *lst)
{
	int	num;

	num = 0;
	while (lst)
	{
		if (lst->index < num)
			return (0);
		num = lst->index;
		lst = lst->next;
	}
	return (1);
}

void	exiter(void)
{
	ft_printf("Error\n");
	exit(1);
}
