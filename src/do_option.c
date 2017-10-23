/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:08:24 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/27 14:30:45 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	print_pile(t_list *lst_a, t_list *lst_b, t_data data)
{
	data.color ? ft_putstr("\n\033[31mPile A:\033[37m") \
		: ft_putstr("\nPile A:");
	if (lst_a)
		while (lst_a)
		{
			write(1, " ", 1);
			ft_putnbr(lst_a->nb);
			lst_a = lst_a->next;
		}
	else
		ft_putstr(" Empty");
	data.color ? ft_putstr("\n\033[36mPile B:\033[37m") \
		: ft_putstr("\nPile B:");
	if (lst_b)
		while (lst_b)
		{
			write(1, " ", 1);
			ft_putnbr(lst_b->nb);
			lst_b = lst_b->next;
		}
	else
		ft_putstr(" Empty");
}

static void	r_print_pile(t_data data)
{
	data.color ? ft_putstr("\n\033[31mPile A:\033[37m") \
		: ft_putstr("\nPile A:");
	if (data.end_a)
		while (data.end_a)
		{
			write(1, " ", 1);
			ft_putnbr(data.end_a->nb);
			data.end_a = data.end_a->prev;
		}
	else
		ft_putstr(" Empty");
	data.color ? ft_putstr("\n\033[36mPile B:\033[37m") \
		: ft_putstr("\nPile B:");
	if (data.end_b)
		while (data.end_b)
		{
			write(1, " ", 1);
			ft_putnbr(data.end_b->nb);
			data.end_b = data.end_b->prev;
		}
	else
		ft_putstr(" Empty");
}

void		do_option(t_list *lst_a, t_list *lst_b, t_data data)
{
	if (data.print)
	{
		if (data.print == 1)
			print_pile(lst_a, lst_b, data);
		else
			r_print_pile(data);
	}
	if (data.move)
	{
		ft_putstr("\nTotal Movement: ");
		ft_putnbr(data.n_move);
	}
}
