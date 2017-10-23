/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:41:08 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/27 17:32:54 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	define_pivot(t_list *lst_a)
{
	int		pivot;
	int		count;
	t_list	*tmp;
	t_list	*start;

	start = lst_a;
	tmp = lst_a;
	while (lst_a)
	{
		count = 0;
		pivot = lst_a->nb;
		while (tmp)
		{
			if (tmp->nb < pivot)
				count++;
			tmp = tmp->next;
		}
		if (count == 2)
			return (pivot);
		else if ((tmp = start))
			lst_a = lst_a->next;
	}
	return (0);
}

static void	pre_sort(t_list **lst_a, t_data *data)
{
	if ((*lst_a)->nb > data->end_a->nb)
	{
		if ((*lst_a)->nb > (*lst_a)->next->nb)
			swap_a(lst_a, data);
		r_rotate_a(lst_a, data);
	}
	if ((*lst_a)->nb > (*lst_a)->next->nb)
		swap_a(lst_a, data);
	if (data->end_a->nb < data->end_a->prev->nb)
	{
		r_rotate_a(lst_a, data);
		r_rotate_a(lst_a, data);
		swap_a(lst_a, data);
		rotate_a(lst_a, data);
		rotate_a(lst_a, data);
	}
}

void		five_sort(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int		cmpt;
	int		pivot;

	cmpt = 0;
	pivot = define_pivot(*lst_a);
	while (cmpt != 2)
	{
		if ((*lst_a)->nb < pivot && ++cmpt)
			push_b(lst_a, lst_b, data);
		else
			rotate_a(lst_a, data);
	}
	if ((*lst_b)->nb < (*lst_b)->next->nb)
		swap_b(lst_b, data);
	pre_sort(lst_a, data);
	push_a(lst_a, lst_b, data);
	push_a(lst_a, lst_b, data);
}
