/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:59:59 by julio             #+#    #+#             */
/*   Updated: 2022/11/02 11:12:39 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_form(va_list arg, const char form)
{
	int	ct;

	ct = 0;
	if (form == 'c')
		ct += ft_putchar((char)va_arg(arg, int));
	else if (form == 's')
		ct += ft_putstr(va_arg(arg, char *));
	else if (form == 'd') 
		ct += ft_putnbr((int)va_arg(arg, int), ct);
    else if (form == 'i')
		ct += ft_putnbr((int)va_arg(arg, int), ct);
	else if (form == 'u')
		ct += ft_putnbr2((unsigned int)va_arg(arg, unsigned int), ct);
	else if (form == 'x')
		ct += ft_putnbr_base((unsigned int)va_arg(arg, unsigned int), "0123456789abcdef", ct);
    else if (form == 'X')
        ct += ft_putnbr_base((unsigned int)va_arg(arg, unsigned int), "0123456789ABCDEF", ct);
	else if (form == '%')
		ct += ft_putchar(va_arg(arg, int));
    else if (form == 'p')
		ct += ft_printaddress(va_arg(arg, void *));
	return (ct);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_form(arg, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (print_len);
}
