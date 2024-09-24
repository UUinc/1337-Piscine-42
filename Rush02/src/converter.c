/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:58:48 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/15 18:37:36 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_numbers	*init_number(t_stock_nbr *stock)
{
	t_numbers	*res;

	res = (t_numbers *)malloc(sizeof(t_numbers));
	if (!res)
		return (NULL);
	res->multiplier = get_multiplier(stock);
	res->first_twenty = get_first_twenty(stock);
	res->tens = get_tens(stock);
	res->stock = stock;
	return (res);
}

t_ui128	get_limit(void)
{
	t_ui128	n;

	n = 1000000000000000000ULL;
	n = n * n;
	return (n);
}

void	count_mul(int *t, t_ui128 *curr_hun, t_ui128 *i, t_ui128 *limit)
{
	*curr_hun = *i / *limit;
	while (*curr_hun == 0)
	{
		*i %= *limit;
		*limit /= 1000;
		*curr_hun = *i / *limit;
		++(*t);
	}
}

char	*converter(char *answer, t_ui128 *curr_hun, int *t, t_numbers *numbers)
{
	char	**multiplier;
	char	**first_twenty;
	char	**tens;

	multiplier = numbers->multiplier;
	first_twenty = numbers->first_twenty;
	tens = numbers->tens;
	if (*curr_hun > 99)
		answer = ft_strcat(ft_fourcat(answer, first_twenty[*curr_hun / 100],
					" ", search_stock(numbers->stock, *curr_hun)), " ");
	*curr_hun = *curr_hun % 100;
	if (*curr_hun > 0 && *curr_hun < 20)
		answer = ft_tricat(answer, first_twenty[*curr_hun], " ");
	else if (*curr_hun % 10 == 0 && *curr_hun != 0)
		answer = ft_tricat(answer, tens[*curr_hun / 10 - 1], " ");
	else if (*curr_hun > 20 && *curr_hun < 100)
	{
		answer = ft_tricat(answer, tens[*curr_hun / 10 - 1], " ");
		answer = ft_tricat(answer, first_twenty[*curr_hun % 10], " ");
	}
	if (*t < 12)
		answer = ft_tricat(answer, multiplier[++(*t)], " ");
	return (answer);
}

char	*number_to_words(t_ui128 n, t_stock_nbr *stock, t_numbers *numbers)
{
	t_ui128		limit;
	t_ui128		curr_hun;
	t_ui128		i;
	int			t;
	char		*answer;

	limit = get_limit();
	t = 0;
	answer = "";
	if (n == 0)
		return (search_stock(stock, n));
	if (n < 20)
		return (get_first_twenty(stock)[n]);
	i = n;
	while (i > 0)
	{
		count_mul(&t, &curr_hun, &i, &limit);
		answer = converter(answer, &curr_hun, &t, numbers);
		i %= limit;
		limit /= 1000;
	}
	answer[ft_strlen(answer) - 1] = '\0';
	return (answer);
}
