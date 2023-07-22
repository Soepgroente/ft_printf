/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:15:49 by vvan-der          #+#    #+#             */
/*   Updated: 2023/07/22 14:41:00 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include "ft_printf.h"

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_writoa(int n);
int		ft_lutoa(size_t args, int base, int b);
int		ft_printf(const char *input, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstrlen_fd(char *s, int fd);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);

#endif
