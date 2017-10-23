/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:19:24 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/28 15:30:42 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_list *lst)
{
	if (lst && lst->next)
	{
		while (lst->next)
		{
			if (lst->nb > lst->next->nb)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}

static void	pre_sort(t_list **lst_a, t_data *data)
{
	if ((*lst_a)->nb > data->end_a->nb)
	{
		if ((*lst_a)->nb > (*lst_a)->next->nb)
			swap_a(lst_a, data);
		if (!check_sort(*lst_a))
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

void		sort(t_list **lst_a, t_list **lst_b, t_data *data)
{
	if (!check_sort(*lst_a))
	{
		if (data->size_a != 5 && data->size_a != 4)
		{
			pre_sort(lst_a, data);
			basic_sort(lst_a, lst_b, data);
		}
		else if (data->size_a != 4)
			five_sort(lst_a, lst_b, data);
		else
			four_sort(lst_a, data);
	}
}
