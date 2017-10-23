/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:44:53 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/27 14:38:06 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	swap_a(t_list **lst_a, t_data *data)
{
	t_list	*tmp;

	if (*lst_a && (*lst_a)->next)
	{
		tmp = (*lst_a)->next;
		if (!tmp->next)
			data->end_a = *lst_a;
		else
			tmp->next->prev = *lst_a;
		(*lst_a)->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = *lst_a;
		(*lst_a)->prev = tmp;
		*lst_a = tmp;
		if (!data->hide)
			!data->n_move ? ft_putstr("sa") : ft_putstr(" sa");
		data->n_move++;
	}
}

void	push_a(t_list **lst_a, t_list **lst_b, t_data *data)
{
	t_list	*tmp;

	if (*lst_b)
	{
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		if (*lst_b)
			(*lst_b)->prev = NULL;
		else
			data->end_b = NULL;
		tmp->next = *lst_a;
		if (*lst_a)
			(*lst_a)->prev = tmp;
		else
			data->end_a = tmp;
		*lst_a = tmp;
		if (!data->hide)
			!data->n_move ? ft_putstr("pa") : ft_putstr(" pa");
		data->n_move++;
	}
}

void	rotate_a(t_list **lst_a, t_data *data)
{
	t_list *tmp;

	if (*lst_a && (*lst_a)->next)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		(*lst_a)->prev = NULL;
		data->end_a->next = tmp;
		tmp->prev = data->end_a;
		tmp->next = NULL;
		data->end_a = tmp;
		if (!data->hide)
			!data->n_move ? ft_putstr("ra") : ft_putstr(" ra");
		data->n_move++;
	}
}

void	r_rotate_a(t_list **lst_a, t_data *data)
{
	t_list *tmp;

	if (*lst_a && (*lst_a)->next)
	{
		tmp = data->end_a;
		data->end_a = data->end_a->prev;
		data->end_a->next = NULL;
		tmp->next = *lst_a;
		tmp->prev = NULL;
		*lst_a = tmp;
		(*lst_a)->next->prev = *lst_a;
		if (!data->hide)
			!data->n_move ? ft_putstr("rra") : ft_putstr(" rra");
		data->n_move++;
	}
}
