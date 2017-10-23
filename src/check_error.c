/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:45:32 by ttridon           #+#    #+#             */
/*   Updated: 2016/04/21 14:42:54 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static long	ft_atoi_mod(char *s)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	return (sign * nb);
}

static void	check_size(char *av)
{
	long nb;

	nb = ft_atoi_mod(av);
	nb = nb >> 31;
	if (nb >= 0)
	{
		if (nb != 0 || ft_strlen(av) > 10)
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
	}
	else
	{
		if (nb != -1 || ft_strlen(av) > 11)
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
	}
}

void		check_error(t_list *lst_a, char *av)
{
	int	i;

	i = av[0] == '-' && av[1] ? 1 : 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		i++;
	}
	i = ft_atoi(av);
	while (lst_a)
	{
		if (lst_a->nb == i)
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		lst_a = lst_a->next;
	}
	check_size(av);
}
