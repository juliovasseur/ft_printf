/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:22:05 by jvasseur          #+#    #+#             */
/*   Updated: 2022/10/21 15:55:07 by jvasseur         ###   ########.fr       */
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

int	ft_putnbr_base(long long nbr, char *base, int cpt)
{
	long int nbtemp;
	long int	i;

	i = 0;
	if (check(base) == 0)
		return (0);
	nbtemp = 0;
	if (nbr < 0)
	{
		nbr = -1 * nbr;
	}
	while (base[i])
		i++;
	if (nbr < i)
		cpt += ft_putchar(base[nbr % i]);
	else
	{
		ft_putnbr_base(nbr / i, base, cpt);
		nbtemp = nbr % i;
		cpt += ft_putchar(base[nbtemp]);
	}
	return (cpt);
}