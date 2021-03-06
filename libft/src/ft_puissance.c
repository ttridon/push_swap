/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:48:54 by ttridon           #+#    #+#             */
/*   Updated: 2016/02/22 19:19:55 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_puissance(int n, int p)
{
	long	nb;

	nb = n;
	while (--p > 0)
		nb = nb * n;
	return (nb);
}
