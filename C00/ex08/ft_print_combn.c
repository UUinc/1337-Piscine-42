/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:30:19 by yalazrek          #+#    #+#             */
/*   Updated: 2024/08/30 10:32:51 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init(char arr[], int n, int x)
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i + x + '0';
		i++;
	}
}

void	ft_print(char arr[], int n)
{
	write(1, arr, n);
}

int	ft_add(char arr[], int n, int index)
{
	int	i;

	i = index + 1;
	arr[index]++;
	if (arr[index] > 10 - n + index + '0')
	{
		return (index);
	}
	while (i < n)
	{
		arr[i] = arr[i - 1] + 1;
		i++;
	}
	return (n - 1);
}

void	ft_print_combn(int n)
{
	int		i;
	char	comb[9];

	ft_init(comb, n, 0);
	i = n - 1;
	while (i >= 0)
	{
		while (comb[i] <= 10 - n + i + '0')
		{
			if (comb[0] == 10 - n + '0')
			{
				ft_init(comb, n, 10 - n);
				ft_print(comb, n);
				return ;
			}
			ft_print(comb, n);
			write(1, ", ", 2);
			comb[i]++;
		}
		i = ft_add(comb, n, i - 1);
	}
}
