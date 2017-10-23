/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:04:39 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/28 15:27:31 by ttridon          ###   ########.fr       */
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

static void	rotate(t_list **lst_a, t_data *data)
{
	if (data->end_a->nb < data->end_a->prev->nb)
	{
		r_rotate_a(lst_a, data);
		r_rotate_a(lst_a, data);
		swap_a(lst_a, data);
		rotate_a(lst_a, data);
		rotate_a(lst_a, data);
	}
}

void		four_sort(t_list **lst_a, t_data *data)
{
	rotate(lst_a, data);
	while ((*lst_a)->nb > data->end_a->nb)
		rotate_a(lst_a, data);
	if ((*lst_a)->next->nb > data->end_a->nb)
	{
		swap_a(lst_a, data);
		rotate_a(lst_a, data);
	}
	while (!check_sort(*lst_a))
	{
		if ((*lst_a)->next->nb > (*lst_a)->next->next->nb)
		{
			rotate_a(lst_a, data);
			swap_a(lst_a, data);
			r_rotate_a(lst_a, data);
		}
		if ((*lst_a)->nb > (*lst_a)->next->nb)
			swap_a(lst_a, data);
	}
}
