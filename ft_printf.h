/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:56:50 by moseddik          #+#    #+#             */
/*   Updated: 2021/12/08 18:28:09 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
void	ft_putstr(char *s, int *len);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int *len, int value, ...);
void	ft_puthex_p_x(int *len, int value, ...);
char	*r_str(int value);

#endif
