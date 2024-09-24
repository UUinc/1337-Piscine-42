/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:03:54 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/04 16:05:45 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_pos(int nb)
{
	int		i;
	int		n;
	char	c;

	i = 1;
	while (nb / i > 9)
		i *= 10;
	while (i > 0)
	{
		n = nb / i;
		c = n + '0';
		write(1, &c, 1);
		nb = nb - n * i;
		i /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	ft_putnbr_pos(nb);
}
