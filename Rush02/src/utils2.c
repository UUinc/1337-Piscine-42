/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:44:22 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/15 18:29:38 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	free_stock(t_stock_nbr *stock)
{
	int	i;

	i = 0;
	while (stock[i].end != 1)
	{
		free(stock[i].str);
		i++;
	}
	free(stock);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(__int128 nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

char	*search_stock(t_stock_nbr *stock, t_ui128 nbr)
{
	int	i;

	i = 0;
	while (stock[i].end != 1)
	{
		if (nbr == stock[i].nbr)
			return (stock[i].str);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len])
		len++;
	return (len);
}
