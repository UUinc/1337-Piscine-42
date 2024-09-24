/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:25:40 by mm-haini          #+#    #+#             */
/*   Updated: 2024/09/03 14:37:08 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_line(int x, char c)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_putchar(c);
		i++;
	}
}

void	ft_print_row(int x, char s, char e, char c)
{
	ft_putchar(s);
	ft_print_line(x - 2, c);
	if (x > 1)
		ft_putchar(e);
}

void	ft_print_col(int x, int y, char c)
{
	int	i;

	i = 0;
	while (i < y - 2)
	{
		ft_putchar(c);
		ft_print_line(x - 2, ' ');
		if (x > 1)
			ft_putchar(c);
		ft_putchar('\n');
		i++;
	}
}

void	rush(int x, int y)
{
	ft_print_row(x, 'A', 'C', 'B');
	ft_putchar('\n');
	ft_print_col(x, y, 'B');
	if (y - 1 < 1)
		return ;
	ft_print_row(x, 'A', 'C', 'B');
	ft_putchar('\n');
}
