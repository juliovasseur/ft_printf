/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:59:59 by julio             #+#    #+#             */
/*   Updated: 2022/10/20 17:31:24 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
    va_list arg;
    va_start (arg, str);
    int i;
    int cpt;

    cpt = 0;
    i = 0;
    while (str[i] != 0)
    {
        if (str[i] != '%')
            cpt += ft_putchar(str[i]);
        if (str[i] == '%' && str[i + 1])
        {
            if (str[i + 1] == 'c')
                cpt += ft_putchar((char)va_arg(arg, int));
            if (str[i + 1] == 's')
                cpt += ft_putstr((char *)va_arg(arg, char *));
            if (str[i + 1] == 'd')
                cpt += ft_putnbr_base((int)va_arg(arg, int), "0123456789", cpt);
            if (str[i + 1] == 'i')
                cpt += ft_putnbr_base((int)va_arg(arg, int), "0123456789", cpt);
            if (str[i + 1] == 'u')
                cpt += ft_putnbr_base2((unsigned int)va_arg(arg, int), "0123456789", cpt);
            if (str[i + 1] == 'x')
                cpt += ft_putnbr_base((int)va_arg(arg, int), "0123456789abcdef", cpt);
			if (str[i + 1] == 'X')
                cpt += ft_putnbr_base((int)va_arg(arg, int), "0123456789ABCDEF", cpt);
			if (str[i + 1] == '%')
                cpt += ft_putchar((char)va_arg(arg, int));
            i++;
        }
        i++;
    }
    va_end(arg);
    return (cpt);
}