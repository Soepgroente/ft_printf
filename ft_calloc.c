/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:27:36 by vvan-der          #+#    #+#             */
/*   Updated: 2023/07/22 14:39:56 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, (count * size));
	return ((void *)str);
}
