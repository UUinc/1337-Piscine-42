/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:29:15 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/09 10:54:31 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_str_char_twice(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_str_non_usable(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		if (str[i] < 32 || (unsigned char)str[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_base(long nbr, char *radix, long base)
{
	if (nbr < base)
	{
		write(1, &radix[nbr], 1);
		return ;
	}
	ft_print_base(nbr / base, radix, base);
	write(1, &radix[nbr % base], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	long	base_len;

	n = (long) nbr;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	if (ft_str_non_usable(base, base_len))
		return ;
	if (ft_str_char_twice(base, base_len))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_print_base(n, base, base_len);
}
