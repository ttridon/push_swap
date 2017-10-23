/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:09:47 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/27 14:38:37 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	swap_b(t_list **lst_b, t_data *data)
{
	t_list	*tmp;

	if (*lst_b && (*lst_b)->next)
	{
		tmp = (*lst_b)->next;
		if (!tmp->next)
			data->end_b = *lst_b;
		else
			tmp->next->prev = *lst_b;
		(*lst_b)->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = *lst_b;
		(*lst_b)->prev = tmp;
		*lst_b = tmp;
		if (!data->hide)
			!data->n_move ? ft_putstr("sb") : ft_putstr(" sb");
		data->n_move++;
	}
}

void	push_b(t_list **lst_a, t_list **lst_b, t_data *data)
{
	t_list	*tmp;

	if (*lst_a)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		if (*lst_a)
			(*lst_a)->prev = NULL;
		else
			data->end_a = NULL;
		tmp->next = *lst_b;
		if (*lst_b)
			(*lst_b)->prev = tmp;
		else
			data->end_b = tmp;
		*lst_b = tmp;
		if (!data->hide)
			!data->n_move ? ft_putstr("pb") : ft_putstr(" pb");
		data->n_move++;
	}
}

void	rotate_b(t_list **lst_b, t_data *data)
{
	t_list *tmp;

	if (*lst_b && (*lst_b)->next)
	{
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		(*lst_b)->prev = NULL;
		data->end_b->next = tmp;
		tmp->prev = data->end_b;
		tmp->next = NULL;
		data->end_b = tmp;
		if (!data->hide)
			!data->n_move ? ft_putstr("rb") : ft_putstr(" rb");
		data->n_move++;
	}
}

void	r_rotate_b(t_list **lst_b, t_data *data)
{
	t_list *tmp;

	if (*lst_b && (*lst_b)->next)
	{
		tmp = data->end_b;
		data->end_b = data->end_b->prev;
		data->end_b->next = NULL;
		tmp->next = *lst_b;
		tmp->prev = NULL;
		*lst_b = tmp;
		(*lst_b)->next->prev = *lst_b;
		if (!data->hide)
			!data->n_move ? ft_putstr("rrb") : ft_putstr(" rrb");
		data->n_move++;
	}
}
