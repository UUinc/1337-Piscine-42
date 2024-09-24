/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:43:07 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/11 14:38:27 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_nbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
		return ;
	}
	ft_print_nbr(nbr / 10);
	ft_print_nbr(nbr % 10);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while ((par + i)->str != 0)
	{
		ft_print_str((par + i)->str);
		write(1, "\n", 1);
		ft_print_nbr((par + i)->size);
		write(1, "\n", 1);
		ft_print_str((par + i)->copy);
		write(1, "\n", 1);
		i++;
	}
}
