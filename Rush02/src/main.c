/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:45:53 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/15 17:57:57 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int			g_error = 0;

int	arg_man(int argc, char **argv, char **filename)
{
	unsigned __int128	nbr;

	if (argc < 2)
	{
		g_error = ARGS_ERROR;
		return (0);
	}
	if (argc == 3)
		*filename = argv[2];
	nbr = ft_atoi(argv[1]);
	return (nbr);
}

int	main(int argc, char **argv)
{
	unsigned __int128	nbr;
	t_stock_nbr			*stock;
	char				*filename;
	char				*result;

	filename = "dict/numbers.dict";
	nbr = arg_man(argc, argv, &filename);
	if (nbr == 0 && (g_error == ATOI_ERROR || g_error == ARGS_ERROR))
	{
		ft_puterror("Error\n");
		return (nbr);
	}
	stock = parse_dict(filename);
	if (g_error == PARSING_ERROR || check_max(stock, nbr) == FALSE)
	{
		ft_puterror("Dict Error\n");
		return (PARSING_ERROR);
	}
	result = number_to_words(nbr, stock, init_number(stock));
	ft_putstr(result);
	free_stock(stock);
	return (0);
}

int	check_max(t_stock_nbr *stock, t_ui128 nbr)
{
	int		i;
	t_ui128	tmp;

	i = 0;
	while (stock[i].end != 1)
		i++;
	tmp = stock[i - 1].nbr;
	if (tmp >= 1000)
	{
		if ((tmp * 1000) - 1 < nbr)
			return (FALSE);
	}
	else if (tmp >= 100)
	{
		if ((tmp * 10) - 1 < nbr)
			return (FALSE);
	}
	else if (tmp < 100)
	{
		if (tmp < nbr)
			return (FALSE);
	}
	return (TRUE);
}
