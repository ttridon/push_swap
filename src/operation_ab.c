/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 14:16:55 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/27 14:39:26 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	swap_ab(t_list **lst_a, t_list **lst_b, t_data *data)
{
	t_list	*tmp;

	if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		tmp = (*lst_a)->next;
		data->end_a = !tmp->next ? *lst_a : data->end_a;
		if (tmp->next)
			tmp->next->prev = *lst_a;
		(*lst_a)->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = *lst_a;
		(*lst_a)->prev = tmp;
		*lst_a = tmp;
		tmp = (*lst_b)->next;
		data->end_b = !tmp->next ? *lst_b : data->end_b;
		if (tmp->next)
			tmp->next->prev = *lst_b;
		(*lst_b)->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = *lst_b;
		(*lst_b)->prev = tmp;
		*lst_b = tmp;
		!data->n_move ? ft_putstr("ss") : ft_putstr(" ss");
		data->n_move++;
	}
}

void	rotate_ab(t_list **lst_a, t_list **lst_b, t_data *data)
{
	t_list	*tmp;

	if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		(*lst_a)->prev = NULL;
		data->end_a->next = tmp;
		tmp->prev = data->end_a;
		tmp->next = NULL;
		data->end_a = tmp;
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		(*lst_b)->prev = NULL;
		data->end_b->next = tmp;
		tmp->prev = data->end_b;
		tmp->next = NULL;
		data->end_b = tmp;
		!data->n_move ? ft_putstr("rr") : ft_putstr(" rr");
		data->n_move++;
	}
}

void	r_rotate_ab(t_list **lst_a, t_list **lst_b, t_data *data)
{
	t_list	*tmp;

	if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		tmp = data->end_a;
		data->end_a = data->end_a->prev;
		data->end_a->next = NULL;
		tmp->next = *lst_a;
		tmp->prev = NULL;
		*lst_a = tmp;
		(*lst_a)->next->prev = *lst_a;
		tmp = data->end_b;
		data->end_b = data->end_b->prev;
		data->end_b->next = NULL;
		tmp->next = *lst_b;
		tmp->prev = NULL;
		*lst_b = tmp;
		(*lst_b)->next->prev = *lst_b;
		!data->n_move ? ft_putstr("rrr") : ft_putstr(" rrr");
		data->n_move++;
	}
}
