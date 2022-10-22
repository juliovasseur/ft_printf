/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 04:07:34 by julio             #+#    #+#             */
/*   Updated: 2022/10/22 04:11:58 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int ct)
{
	if (nb < 0)
	{
		ct += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ct += ft_putnbr(nb / 10, ct);
		ft_putnbr(nb % 10, ct);
	}
	else
	{
		ct += ft_putchar(nb + 48);
	}
    return (ct);
}
