/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:22:05 by jvasseur          #+#    #+#             */
/*   Updated: 2022/10/20 16:33:20 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char *base)
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

void	check2(void)
{
	write(1, "2147483648", 10);
}

int	ft_putnbr_base(int nbr, char *base, int cpt)
{
	int	nbtemp;
	int	i;

	i = 0;
	if (check(base) == 0)
		return (1);
	nbtemp = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
			check2();
		else
			nbr = -nbr;
	}
	while (base[i])
		i++;
	if (nbr < i)
        cpt += ft_putchar(base[nbr % i]);
	else
	{
		cpt += ft_putnbr_base(nbr / i, base, cpt);
		nbtemp = nbr % i;
		ft_putchar(base[nbtemp]);
	}
	return (cpt);
}