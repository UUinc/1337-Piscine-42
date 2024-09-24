/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:36:41 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/15 17:54:22 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

t_stock_nbr	*sort_dict(t_stock_nbr *stock)
{
	int			i;
	int			j;
	t_stock_nbr	tmp;

	i = 0;
	while (stock[i + 1].end != 1)
	{
		j = i + 1;
		while (stock[j].end != 1)
		{
			if (stock[i].nbr > stock[j].nbr)
			{
				tmp = stock[i];
				stock[i] = stock[j];
				stock[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (stock);
}

int	count_file_lines(char *filename)
{
	char	c;
	int		counter;
	int		fd;

	fd = open_file(filename);
	counter = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			counter++;
	}
	close(fd);
	return (counter);
}

t_stock_nbr	*fill_dict(char *filename, t_stock_nbr *stock, int size)
{
	int		fd;
	int		buf_idx;
	char	buffer[MAX_SIZE];

	fd = open_file(filename);
	if (fd == -1)
		return (NULL);
	buf_idx = 0;
	while (buf_idx < size)
	{
		read_file(fd, buffer);
		if (!buffer[0])
		{
			size--;
			continue ;
		}
		stock[buf_idx].nbr = ft_atoi(buffer);
		stock[buf_idx].str = ft_clean_strdup(buffer, MAX_SIZE);
		if (g_error == ATOI_ERROR || g_error == MEMORY_ERROR)
			g_error = PARSING_ERROR;
		buf_idx++;
	}
	stock[buf_idx].end = TRUE;
	close(fd);
	return (stock);
}

t_stock_nbr	*parse_dict(char *filename)
{
	t_stock_nbr	*stock;
	int			size;

	size = count_file_lines(filename);
	if (size == -1)
		return (NULL);
	stock = (t_stock_nbr *)malloc(sizeof(t_stock_nbr) * (size + 1));
	if (!stock)
		return (NULL);
	if (fill_dict(filename, stock, size) == NULL)
		return (NULL);
	if (g_error == PARSING_ERROR)
	{
		free_stock(stock);
		return (NULL);
	}
	sort_dict(stock);
	return (stock);
}

void	print_dict(t_stock_nbr *stock)
{
	int	i;

	i = 0;
	while (stock[i].end != 1)
	{
		ft_putnbr(stock[i].nbr);
		ft_putstr(" - ");
		ft_putstr(stock[i].str);
		ft_putchar('\n');
		free(stock[i].str);
		i++;
	}
	free(stock);
}
