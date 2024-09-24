/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:27:43 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/06 11:50:46 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_board(int board[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j])
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_valid(int row, int col, int board[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		if (board[i][col])
			return (0);
		i++;
	}
	i = row - ft_min(row, col);
	j = col - ft_min(row, col);
	while (i < 10 && j < 10)
	{
		if (board[i++][j++])
			return (0);
	}
	i = row - ft_min(row, 9 - col);
	j = col + ft_min(row, 9 - col);
	while (i < 10 && j >= 0)
	{
		if (board[i++][j--])
			return (0);
	}
	return (1);
}

int	ft_ten_queens(int row, int board[10][10])
{
	int			i;
	static int	count;

	if (row > 9)
	{
		ft_print_board(board);
		count++;
		return (count);
	}
	i = 0;
	while (i < 10)
	{
		if (!ft_valid(row, i, board))
		{
			i++;
			continue ;
		}
		board[row][i] = 1;
		ft_ten_queens(row + 1, board);
		board[row][i] = 0;
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	j;
	int	board[10][10];

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
			board[i][j++] = 0;
		i++;
	}
	return (ft_ten_queens(0, board));
}
