/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:29:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 14:30:00 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	destroy_object(t_object *obj)
{
	ft_lstclear(&obj->stack_a.list, free);
	ft_lstclear(&obj->stack_b.list, free);
	ft_lstclear(&obj->instructions, free);
}
