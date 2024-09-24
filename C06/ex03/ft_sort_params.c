/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:14:07 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/05 08:48:00 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str + i, 1);
	write(1, "\n", 1);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

void	ft_bubble_sort(char **strs, int size)
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
			if (ft_strcmp(strs[j], strs[i]) < 0)
			{
				ft_swap(&strs[i], &strs[j]);
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

int	main(int argc, char **argv)
{
	int	i;

	ft_bubble_sort(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
		ft_print_str(argv[i++]);
	return (0);
}
