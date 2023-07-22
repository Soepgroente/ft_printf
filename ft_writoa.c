/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:06:09 by vvan-der          #+#    #+#             */
/*   Updated: 2022/12/15 16:49:24 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "ft_printf.h"

static int	length(int x)
{
	int	i;

	i = 0;
	if (x <= 0)
		i++;
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

int	ft_writoa(int n)
{
	char	*res;
	int		x;
	long	y;

	x = length(n);
	y = (long) n;
	res = ft_calloc(x + 1, sizeof(char));
	if (!res)
		return (-1);
	if (n < 0)
		y *= -1;
	x--;
	while (x > 0 && y > 9)
	{
		res[x] = (y % 10) + 48;
		y /= 10;
		x--;
	}
	res[x] = y + 48;
	if (n < 0)
		res[0] = '-';
	x = ft_putstrlen_fd(res, 1);
	free(res);
	return (x);
}
