/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:57:13 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/15 18:40:32 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	**get_multiplier(t_stock_nbr *stock)
{
	char	**multiplier;
	int		i;
	int		counter;
	int		buf_idx;

	counter = 0;
	i = 0;
	while (stock[i].end != 1)
	{
		if (stock[i].nbr >= 1000)
			counter++;
		i++;
	}
	if (counter == 0)
		return (NULL);
	multiplier = (char **)malloc(sizeof(char *) * (counter + 2));
	buf_idx = 0;
	multiplier[buf_idx++] = NULL;
	while (i >= 0 && stock[--i].nbr >= 1000)
	{
		multiplier[buf_idx++] = stock[i].str;
	}
	multiplier[buf_idx] = NULL;
	return (multiplier);
}

char	**get_first_twenty(t_stock_nbr *stock)
{
	char	**first_twenty;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (stock[i].end != 1)
	{
		if (stock[i].nbr > 0 && stock[i].nbr < 20)
			counter++;
		i++;
	}
	first_twenty = (char **)malloc(sizeof(char *) * (counter + 2));
	i = 0;
	first_twenty[i++] = NULL;
	while (stock[i].end != 1 && stock[i].nbr < 20)
	{
		first_twenty[i] = stock[i].str;
		i++;
	}
	first_twenty[counter] = NULL;
	return (first_twenty);
}

char	**get_tens(t_stock_nbr *stock)
{
	char	**tens;
	int		i;
	int		counter;
	int		buf_idx;

	i = 0;
	counter = 0;
	while (stock[i].end != 1)
	{
		if (stock[i].nbr >= 20 && stock[i].nbr < 100)
			counter++;
		i++;
	}
	tens = (char **)malloc(sizeof(char *) * (counter + 2));
	i = 0;
	buf_idx = 0;
	tens[buf_idx++] = NULL;
	while (stock[i].end != 1)
	{
		if (stock[i].nbr >= 20 && stock[i].nbr < 100)
			tens[buf_idx++] = stock[i].str;
		i++;
	}
	tens[buf_idx] = NULL;
	return (tens);
}
