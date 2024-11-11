/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:26:24 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/09 22:24:55 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}

int	ft_print_format(char ch, va_list args)
{
	int	ct;

	ct = 0;
	if (ch == 'c')
		ct = ct + ft_print_ch(va_arg(args, int));
	else if (ch == 's')
		ct = ct + ft_print_str(va_arg(args, char *));
	else if (ch == 'd' || ch == 'i')
		ct = ct + ft_print_int((long)(va_arg(args, int)), 10);
	else if (ch == 'u')
		ct = ct + ft_print_int((long)(va_arg(args, unsigned int)), 10);
	else if (ch == 'x')
		ct = ct + ft_print_int((long)(va_arg(args, unsigned int)), 16);
	else if (ch == 'X')
		ct = ct + ft_print_hex_upper((long)(va_arg(args, unsigned int)), 16);
	else if (ch == 'p')
	{
		write(1, "0x", 2);
		ct += 2 + ft_print_ptr((long long)(va_arg(args, unsigned long long)));
	}
	else if (ch == '%')
		ct = ct + ft_print_percent();
	else
		ct = ct + write(1, &ch, 1);
	return (ct);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ct;

	va_start(args, format);
	ct = 0;
	while (*format)
	{
		if (*format == '%')
			ct = ct + ft_print_format(*(++format), args);
		else
			ct = ct + write(1, format, 1);
		++format;
	}
	va_end(args);
	return (ct);
}
