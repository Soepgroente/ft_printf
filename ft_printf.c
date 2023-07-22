/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:41 by vvan-der          #+#    #+#             */
/*   Updated: 2023/07/22 14:42:14 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_ptr(void *arg)
{
	int	x;

	x = write(1, "0x", 2);
	if (x == -1)
		return (x);
	x = ft_lutoa((size_t) arg, 16, 0);
	if (x == -1)
		return (-1);
	return (x + 2);
}

static int	ft_handle(const char *input, va_list args)
{
	if (*input == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (*input == 's')
		return (ft_putstrlen_fd(va_arg(args, char *), 1));
	else if (*input == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (*input == 'd' || *input == 'i')
		return (ft_writoa(va_arg(args, int)));
	else if (*input == 'u')
		return (ft_lutoa(va_arg(args, unsigned int), 10, 0));
	else if (*input == 'x')
		return (ft_lutoa(va_arg(args, unsigned int), 16, 0));
	else if (*input == 'X')
		return (ft_lutoa(va_arg(args, unsigned int), 16, 1));
	else if (*input == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

static int	ft_gobrr(const char *input, va_list args, int i, int count)
{
	int	write_ret;

	while (input[i])
	{
		write_ret = 0;
		if (input[i] == '%' && (input [i + 1]))
		{
			i++;
			if (ft_strchr("cspdiuxX%", input[i]))
			{
				write_ret = ft_handle(&input[i], args);
				if (write_ret == -1)
					return (-1);
			}
		}
		else if (input[i] != '%')
		{
			write_ret = ft_putchar_fd(input[i], 1);
			if (write_ret == -1)
				return (-1);
		}
		count += write_ret;
		i++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		write_ret;
	int		count;

	i = 0;
	write_ret = 0;
	count = 0;
	va_start(args, input);
	count = ft_gobrr(input, args, i, count);
	va_end(args);
	return (count);
}

/* int	main()
{
	char	*string = "abc%%%%%shiakj";
	int	input = -8273582;
	int	ret_value	= ft_printf("\n %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	int ret_value2	= printf("\n %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("\nRes1:%d\nRes2:%d\n", ret_value, ret_value2);
} */