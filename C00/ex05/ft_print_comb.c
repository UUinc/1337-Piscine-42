/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:01:05 by yalazrek          #+#    #+#             */
/*   Updated: 2024/08/29 14:22:02 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcomb(char c, char c2, char c3)
{
	write(1, &c, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 2;
	while (i < 7)
	{
		while (j <= 8)
		{
			while (k <= 9)
			{
				ft_putcomb(i + '0', j + '0', k + '0');
				k = k + 1;
			}
			j = j + 1;
			k = j + 1;
		}
		i = i + 1;
		j = i + 1;
		k = j + 1;
	}
	write(1, "789", 3);
}
