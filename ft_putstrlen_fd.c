/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:32:27 by vvan-der          #+#    #+#             */
/*   Updated: 2023/07/22 14:40:41 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
