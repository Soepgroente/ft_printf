/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:32:27 by vvan-der          #+#    #+#             */
/*   Updated: 2022/12/15 16:43:14 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_putstrlen_fd(char *s, int fd)
{
	int	x;

	if (!s)
	{
		x = write(1, "(null)", 6);
		return (x);
	}
	x = write(fd, s, ft_strlen(s));
	return (x);
}
