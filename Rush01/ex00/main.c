/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:49:32 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/09 10:31:32 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		*ft_input(char *input_str);
int		*ft_get_permutation(void);
void	ft_all_permutations(int *input, int *permut, int board[4][4]);

int	main(int argc, char **argv)
{
	int	*input;
	int	*permut;
	int	board[4][4];

	if (argc != 2)
	{
		write(2, "Error args\n", 6);
		return (1);
	}
	input = ft_input(argv[1]);
	if (input == NULL)
	{
		write(2, "Error input\n", 6);
		return (1);
	}
	permut = ft_get_permutation();
	ft_all_permutations(input, permut, board);
	return (0);
}
