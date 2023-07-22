/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:22:35 by vvan-der          #+#    #+#             */
/*   Updated: 2022/12/14 18:36:35 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}
