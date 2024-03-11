/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:30:57 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/10 18:11:32 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"
# include "utils/ft_printf/includes/libftprintf.h"

typedef struct s_object
{
	t_list	*numbers;
}	t_object;

int		ft_lstappenditem(t_list **lst, void *content);
int		parse(t_object *obj, char **strs);
void	exiter(void);
void	free_memory(char **strs);

#endif
