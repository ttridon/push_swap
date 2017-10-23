/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:11:54 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/28 15:16:58 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_list
{
	int				nb;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_data
{
	int				size_a;
	int				size_b;
	int				n_move;
	int				color;
	int				move;
	int				print;
	int				hide;
	t_list			*end_a;
	t_list			*end_b;
}					t_data;

void				swap_a(t_list **lst_a, t_data *data);
void				swap_b(t_list **lst_b, t_data *data);
void				push_a(t_list **lst_a, t_list **lst_b, t_data *data);
void				push_b(t_list **lst_a, t_list **lst_b, t_data *data);
void				rotate_a(t_list **lst_a, t_data *data);
void				rotate_b(t_list **lst_b, t_data *data);
void				r_rotate_a(t_list **lst_a, t_data *data);
void				r_rotate_b(t_list **lst_b, t_data *data);
void				swap_ab(t_list **lst_a, t_list **lst_b, t_data *data);
void				rotate_ab(t_list **lst_a, t_list **lst_b, t_data *data);
void				r_rotate_ab(t_list **lst_a, t_list **lst_b, t_data *data);
void				check_error(t_list *lst_a, char *av);
void				sort(t_list **lst_a, t_list **lst_b, t_data *data);
void				basic_sort(t_list **lst_a, t_list **lst_b, t_data *data);
void				five_sort(t_list **lst_a, t_list **lst_b, t_data *data);
void				four_sort(t_list **lst_a, t_data *data);
void				do_option(t_list *lst_a, t_list *lst_b, t_data data);

#endif
