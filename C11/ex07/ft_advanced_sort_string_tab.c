/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:08:01 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/13 21:29:25 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

int	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	return (0);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	is_sorted;
	int	size;

	size = ft_size(tab);
	i = 0;
	is_sorted = 1;
	while (i < size)
	{
		j = i + 1;
		is_sorted = 1;
		while (j < size)
		{
			if (cmp(tab[j], tab[i]) < 0)
				is_sorted = ft_swap(&tab[i], &tab[j]);
			i++;
			j++;
		}
		i = 0;
		size--;
		if (is_sorted)
			break ;
	}
}
