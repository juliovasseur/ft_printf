/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:08:49 by jvasseur          #+#    #+#             */
/*   Updated: 2022/10/21 18:03:37 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	check3(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{	
		if (base[i] < 32 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int	ft_putnbr_base3(unsigned long long nbr, char *base)
{
	unsigned long long nbtemp;
	unsigned long long i;
    unsigned long long cpt;

    cpt = 0;
	i = 16;
	if (check3(base) == 0)
		return (0);
	nbtemp = 0;
	if (nbr < i)
		cpt += ft_putchar(base[nbr % i]);
	else
	{
		ft_putnbr_base3(nbr / i, base);
		nbtemp = nbr % i;
		cpt += ft_putchar(base[nbtemp]);
	}
	return (cpt);
}

int	ft_printaddress(void *nb)
{
    int cpt;
    unsigned long long nbr;

    cpt = 0;
    nbr = (unsigned long long) nb;
	if ( nbr == 0)
        cpt += write(1, "(nil)" , 5);
    else 
    {
        cpt += write(1, "0x", 2);
        cpt += ft_putnbr_base3(nbr, "123456789abcdef");
    }
	return (cpt);
}