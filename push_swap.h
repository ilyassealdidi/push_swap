/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:30:57 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/13 19:23:57 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"
# include "utils/ft_printf/includes/libftprintf.h"

typedef struct s_object
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_object;

int		ft_lstswap_content(t_list *item1, t_list *item2);
void	swap(t_list *stack_a, t_list *stack_b);
int		ft_lstappenditem(t_list **lst, void *content);
void	list_init(t_object *obj, char **strs);
void	exiter(void);
void	free_memory(char **strs);
void	push(t_list **stack_from, t_list **stack_to, char *instruction);

#endif
