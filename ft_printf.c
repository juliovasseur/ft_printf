/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:59:59 by julio             #+#    #+#             */
/*   Updated: 2022/10/20 04:04:00 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>



int    ft_putchar(char s)
{
    write(1, &s, 1);
    return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
    return (i);
}

void ft_putnbr(int n)
{
	int	nbtemp;

	nbtemp = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{	
			write(1, "2147483648", 10);
			return ;
		}
		else
			n = -n;
	}
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		nbtemp = n % 10;
		ft_putchar(nbtemp + 48);
	}
}


int ft_printf(const char *str, ...)
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
                ft_putnbr((int)va_arg(arg, int));
            if (str[i + 1] == 'i')
                ft_putnbr((int)va_arg(arg, int));
            if (str[i + 1] == 'u')
                ft_putnbr((int)va_arg(arg, int));
            i++;
        }
        i++;
    }
    va_end(arg);
    return (cpt);
}

int main()
{
    int i;

    i = 012572,2552;
    ft_printf("bonjour je suis C%i\n", i);
    printf("bonjour je suis C%i\n", i);
}

