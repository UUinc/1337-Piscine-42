/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:07:08 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/03 17:18:51 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_print(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] <= 31 || str[i] >= 127)
		{
			write(1, ".", 1);
			i++;
			continue ;
		}
		write(1, str + i, 1);
		i++;
	}
}

void	ft_print_hexa(char *addr_buff, long addr_value)
{
	static unsigned int	i;
	static unsigned int	count;

	if (addr_value < 16)
	{
		count++;
		addr_buff[16 - count] = "0123456789abcdef"[addr_value];
		i = 0;
		while (i < 16 - count)
			addr_buff[i++] = '0';
		return ;
	}
	count++;
	ft_print_hexa(addr_buff, addr_value / 16);
	addr_buff[16 - --count] = "0123456789abcdef"[addr_value % 16];
	if (count == 1)
		count = 0;
}

void	ft_print_str_hexa(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		write(1, &"0123456789abcdef"[(unsigned char)str[i] / 16], 1);
		write(1, &"0123456789abcdef"[(unsigned char)str[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	nbr;
	char			addr_buff[17];
	char			str[17];

	i = 0;
	len = size / 16;
	nbr = 16;
	while (i <= len)
	{
		ft_print_hexa(addr_buff, (long)(addr + 16 * i));
		ft_print(addr_buff, 16);
		write(1, ": ", 2);
		if (i == len)
			nbr = size % 16;
		ft_strlcpy(str, (char *) addr + 16 * i, nbr + 1);
		ft_print_str_hexa(str, nbr);
		ft_print(str, nbr);
		write(1, "\n", 1);
		i++;
	}
	return (NULL);
}
