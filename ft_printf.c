/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:23:21 by moseddik          #+#    #+#             */
/*   Updated: 2021/12/12 15:15:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf2(const char *fmt, va_list args, int *len)
{
	if (*fmt == 'c')
		ft_putchar(va_arg(args, int), len);
	else if ((*fmt == 'd' || *fmt == 'i'))
		ft_putnbr(len, 1, va_arg(args, int));
	else if (*fmt == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (*fmt == 'p')
	{
		ft_putstr("0x", len);
		ft_puthex_p_x(len, 1, va_arg(args, unsigned long int));
	}
	else if (*fmt == 'u')
		ft_putnbr(len, 0, va_arg(args, unsigned int));
	else if (*fmt == 'x')
		ft_puthex_p_x(len, 0, va_arg(args, int));
	else if (*fmt == 'X')
		ft_puthex_p_x(len, 2, va_arg(args, int));
	else if (*fmt == '%')
		ft_putchar('%', len);
	else
		ft_putchar(*fmt, len);
}

static void	sharp(const char *fmt, int *value2, va_list args, int *len)
{
	int	arg;

	if (*fmt == '#')
	{
		arg = va_arg(args, int);
		*value2 = 1;
		if (*(fmt + 1) == 'x')
		{
			if (arg != 0)
				ft_putstr("0x", len);
			ft_puthex_p_x(len, 0, arg);
		}
		else if (*(fmt + 1) == 'X')
		{
			if (arg != 0)
				ft_putstr("0X", len);
			ft_puthex_p_x(len, 2, arg);
		}
	}
}

static void	space(const char *fmt, int *value2, va_list args, int *len)
{
	int	arg;

	if (*fmt == ' ')
	{
		arg = va_arg(args, int);
		*value2 = 1;
		if (arg >= 0)
			ft_putchar(' ', len);
		if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i')
			ft_putnbr(len, 1, arg);
	}
}

static int	get_flags(const char *fmt, va_list args, int *len)
{
	int	arg;
	int	value2;

	value2 = 0;
	while (*fmt == '+' || *fmt == ' ' || *fmt == '#')
		fmt++;
	fmt--;
	if (*fmt == '+')
	{
		arg = va_arg(args, int);
		value2 = 1;
		if (arg >= 0)
			ft_putchar('+', len);
		if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i')
			ft_putnbr(len, 1, arg);
	}
	space(fmt, &value2, args, len);
	sharp(fmt, &value2, args, len);
	return (value2);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	int		value2;

	va_start(args, fmt);
	len = 0;
	while (*fmt != '\0')
	{
		value2 = 0;
		if (*fmt != '%')
			ft_putchar(*fmt, &len);
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '+' || *fmt == '#' || *fmt == ' ')
				value2 = get_flags(fmt, args, &len);
			while (*fmt == '+' || *fmt == ' ' || *fmt == '#')
				fmt++;
			if (value2 == 0)
				ft_printf2(fmt, args, &len);
		}
		fmt++;
	}
	va_end(args);
	return (len);
}
