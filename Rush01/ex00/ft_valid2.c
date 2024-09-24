/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:15:16 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/08 16:09:18 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_valid_row(char view, int value, int row, int board[4][4]);
int	ft_is_valid_col(char view, int value, int col, int board[4][4]);

// column up and down
int	ft_is_columns_valid(int *input, int board[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!ft_is_valid_col('u', input[i], i, board))
			return (0);
		i++;
	}
	while (i < 8)
	{
		if (!ft_is_valid_col('d', input[i], i - 4, board))
			return (0);
		i++;
	}
	return (1);
}

// row left and right
int	ft_is_rows_valid(int *input, int board[4][4])
{
	int	i;

	i = 8;
	while (i < 12)
	{
		if (!ft_is_valid_row('l', input[i], i - 8, board))
			return (0);
		i++;
	}
	while (i < 16)
	{
		if (!ft_is_valid_row('r', input[i], i - 12, board))
			return (0);
		i++;
	}
	return (1);
}
