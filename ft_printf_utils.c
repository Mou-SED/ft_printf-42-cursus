/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:56:03 by moseddik          #+#    #+#             */
/*   Updated: 2021/12/12 15:16:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int *len, int value, ...)
{
	long	nb;
	va_list	args;

	nb = 0;
	va_start(args, value);
	if (value == 1)
		nb = va_arg(args, int);
	else if (value == 0)
		nb = va_arg(args, unsigned int);
	va_end(args);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', len);
	}
	if (nb > 9)
	{
		ft_putnbr(len, value, nb / 10);
		ft_putnbr(len, value, nb % 10);
	}
	else
		ft_putchar(nb + '0', len);
}

char	*r_str(int value)
{
	if (value == 1 || value == 0)
		return ("0123456789abcdef");
	else if (value == 2)
		return ("0123456789ABCDEF");
	return (NULL);
}

void	ft_puthex_p_x(int *len, int value, ...)
{
	unsigned long int	nb;
	va_list				args;
	char				*str;

	nb = 0;
	va_start(args, value);
	str = r_str(value);
	if (value == 1)
		nb = va_arg(args, unsigned long int);
	else
		nb = va_arg(args, unsigned int);
	va_end(args);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', len);
	}
	if (nb >= 16)
	{
		ft_puthex_p_x(len, value, nb / 16);
		ft_puthex_p_x(len, value, nb % 16);
	}
	else
		ft_putchar(str[nb], len);
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	if (!s)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		*len += write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c, int *len)
{
		*len += write(1, &c, 1);
}
