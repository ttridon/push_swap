/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:00:16 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/25 15:31:50 by ttridon          ###   ########.fr       */
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

static int	define_rotate(t_list *lst, int smaller)
{
	int left;
	int right;

	left = 0;
	right = 0;
	while (lst->nb != smaller)
	{
		lst = lst->next;
		left++;
	}
	while (lst->next)
		lst = lst->next;
	while (lst->nb != smaller)
	{
		lst = lst->prev;
		right++;
	}
	if (left < right)
		return (1);
	else
		return (0);
}

static int	define_smaller(t_list *lst)
{
	int smaller;

	smaller = lst->nb;
	while (lst)
	{
		if (smaller < lst->nb)
			smaller = lst->nb;
		lst = lst->next;
	}
	return (smaller);
}

void		basic_sort(t_list **lst_a, t_list **lst_b, t_data *data)
{
	int smaller;

	if (!check_sort(*lst_a))
	{
		while (*lst_a)
			push_b(lst_a, lst_b, data);
		while (*lst_b)
		{
			smaller = define_smaller(*lst_b);
			if (define_rotate(*lst_b, smaller))
				while ((*lst_b)->nb != smaller)
					rotate_b(lst_b, data);
			else
				while ((*lst_b)->nb != smaller)
					r_rotate_b(lst_b, data);
			push_a(lst_a, lst_b, data);
		}
	}
}
