/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:37:32 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/08 20:48:46 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_duplicate(int *nbrs);

int	ft_is_valid_left(int value, int board[4])
{
	int	i;
	int	j;
	int	tmp[4];

	if (ft_is_duplicate(board))
		return (0);
	i = -1;
	while (++i < 4)
		tmp[i] = board[i];
	i = -1;
	while (++i < 3)
	{
		j = i;
		while (++j < 4)
			if (tmp[i] > tmp[j])
				tmp[j] = 0;
	}
	i = 0;
	j = 0;
	while (i < 4)
		if (tmp[i++] != 0)
			j++;
	if (value == j)
		return (1);
	return (0);
}

int	ft_is_valid_right(int value, int board[4])
{
	int	i;
	int	j;
	int	tmp[4];

	if (ft_is_duplicate(board))
		return (0);
	i = -1;
	while (++i < 4)
		tmp[i] = board[i];
	i = 4;
	while (--i > 0)
	{
		j = i;
		while (--j >= 0)
			if (tmp[i] > tmp[j])
				tmp[j] = 0;
	}
	i = 0;
	j = 0;
	while (i < 4)
		if (tmp[i++] != 0)
			j++;
	if (value == j)
		return (1);
	return (0);
}

// view: l/left | u/up or r/right | d/down
int	ft_is_valid_view(char view, int value, int board[4])
{
	if (view == 'l' || view == 'u')
	{
		return (ft_is_valid_left(value, board));
	}
	else if (view == 'r' || view == 'd')
	{
		return (ft_is_valid_right(value, board));
	}
	return (-1);
}

int	ft_is_valid_row(char view, int value, int row, int board[4][4])
{
	return (ft_is_valid_view(view, value, board[row]));
}

int	ft_is_valid_col(char view, int value, int col, int board[4][4])
{
	int	i;
	int	column[4];

	i = 0;
	while (i < 4)
	{
		column[i] = board[i][col];
		i++;
	}
	return (ft_is_valid_view(view, value, column));
}
