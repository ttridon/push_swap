/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:16:21 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/27 14:42:14 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void		check_option(char **av, int *i, t_data *data)
{
	int	cond;

	data->color = 0;
	data->move = 0;
	data->print = 0;
	data->hide = 0;
	cond = 0;
	while (cond != 1 && av[++(*i)])
	{
		if (!ft_strcmp(av[*i], "-c"))
			data->color = 1;
		else if (!ft_strcmp(av[*i], "-m"))
			data->move = 1;
		else if (!ft_strcmp(av[*i], "-p"))
			data->print = 1;
		else if (!data->print && !ft_strcmp(av[*i], "-rp"))
			data->print = -1;
		else if (!ft_strcmp(av[*i], "-h"))
			data->hide = 1;
		else
			cond = 1;
	}
}

static t_list	*creat_elem(int c)
{
	t_list *elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		ft_putstr_fd("Error\n", 2);
	elem->nb = c;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

static void		add_elem(t_list **lst, t_list *elem, t_data *data)
{
	t_list *tmp;

	tmp = *lst;
	if (!*lst)
		*lst = elem;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
	}
	data->end_a = elem;
}

int				main(int ac, char **av)
{
	int		i;
	t_data	data;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	data.size_a = 0;
	data.size_b = 0;
	data.n_move = 0;
	if (ac > 1)
	{
		i = 0;
		check_option(av, &i, &data);
		while (av[i])
		{
			check_error(lst_a, av[i]);
			add_elem(&lst_a, creat_elem(ft_atoi(av[i])), &data);
			data.size_a++;
			i++;
		}
	}
	sort(&lst_a, &lst_b, &data);
	do_option(lst_a, lst_b, data);
	ft_putstr("\n");
}
