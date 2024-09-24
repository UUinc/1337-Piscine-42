/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:20:15 by yalazrek          #+#    #+#             */
/*   Updated: 2024/08/29 18:45:07 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char c, char c1, char c2, char c3)
{
	write(1, &c, 1);
	write(1, &c1, 1);
	write(1, " ", 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	write(1, ", ", 2);
}

void	ft_print_comb(int i, int j)
{
	int	k;
	int	l;

	k = i;
	l = j + 1;
	if (l > 9)
	{
		l = 0;
		k++;
	}
	if (k > 9)
		return ;
	while (k <= 9)
	{
		while (l <= 9)
		{
			ft_print(i + 48, j + 48, k + 48, l + 48);
			l++;
		}
		l = 0;
		k++;
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 9)
	{
		while (j <= 9)
		{
			if (i == 9 && j == 8)
			{
				write(1, "98 99", 5);
				return ;
			}
			ft_print_comb(i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
