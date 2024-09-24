/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:09:05 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/01 01:31:36 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	ft_bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < size)
	{
		j = i + 1;
		is_sorted = 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				ft_swap(tab + i, tab + j);
				is_sorted = 0;
			}
			i++;
			j++;
		}
		i = 0;
		size--;
		if (is_sorted)
			break ;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_bubble_sort(tab, size);
}
