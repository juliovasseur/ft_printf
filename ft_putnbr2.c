/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:40:07 by julio             #+#    #+#             */
/*   Updated: 2022/11/02 11:14:13 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr2(unsigned int nb, int ct)
{
    if (nb > 0 && nb < 10 )
        ct += ft_putchar(nb + '0');
    else
    {
        ct += ft_putnbr2(nb / 10, ct);
        ft_putnbr2(nb % 10, ct);
    }
    return (ct);
}