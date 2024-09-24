/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:04:52 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/09 10:30:22 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_columns_valid(int *input, int board[4][4]);
int		ft_is_rows_valid(int *input, int board[4][4]);
void	ft_print_board(int board[4][4]);

int	ft_is_valid(int	*input, int board[4][4])
{
	if (!ft_is_columns_valid(input, board))
		return (0);
	if (!ft_is_rows_valid(input, board))
		return (0);
	return (1);
}

int	*ft_intncpy(int *dest, int value, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = value % 10;
		value /= 10;
		i++;
	}
	return (dest);
}

int	ft_checker(int *c, int *input, int *permut, int board[4][4])
{
	ft_intncpy(board[0], permut[c[0]], 4);
	ft_intncpy(board[1], permut[c[1]], 4);
	ft_intncpy(board[2], permut[c[2]], 4);
	ft_intncpy(board[3], permut[c[3]], 4);
	if (ft_is_valid(input, board))
	{
		ft_print_board(board);
		return (1);
	}
	return (0);
}

void	ft_all_permutations(int *input, int *permut, int board[4][4])
{
	int	c[4];

	c[0] = 0;
	while (c[0] < 24)
	{
		c[1] = 0;
		while (c[1] < 24)
		{
			c[2] = 0;
			while (c[2] < 24)
			{
				c[3] = 0;
				while (c[3] < 24)
				{
					if (ft_checker(c, input, permut, board))
						return ;
					c[3]++;
				}
				c[2]++;
			}
			c[1]++;
		}
		c[0]++;
	}
	write(2, "Error", 5);
}
