/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:30:57 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/25 02:18:35 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/includes/libftprintf.h"

typedef struct s_object
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_object;

/*		Sort			*/
int		is_sorted(t_list *lst);
void	sort_three(t_object *obj);
void	sort(t_object *obj);

/*		Parsing			*/
void	list_init(t_object *obj, char **strs);

/*		List Utilities	*/
int		ft_lstappenditem(t_list **lst, void *content);
int		ft_lstshift_down(t_list **lst);

/*		Instructions	*/
void	push(t_list **stack_from, t_list **stack_to, char *instruction);
void	swap(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack_a, t_list **stack_b);

/*		Utilities		*/
void	exiter(void);

#endif
