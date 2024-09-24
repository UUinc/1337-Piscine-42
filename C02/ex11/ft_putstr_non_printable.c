/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:31:39 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/05 10:43:43 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_non_printable(char c)
{
	if (c <= 31 || c >= 127)
		return (1);
	return (0);
}

void	ft_put_hexa(unsigned char c)
{
	char *base = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_non_printable(str[i]))
		{
			ft_put_hexa(str[i]);
		}
		else
		{
			write(1, str + i, 1);
		}
		i++;
	}
}
