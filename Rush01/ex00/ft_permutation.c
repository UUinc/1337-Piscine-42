/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permutation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:02:58 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/08 18:06:58 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_duplicate(int *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (nbrs[i] == nbrs[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_valid_nbr(int nbr)
{
	int	i;
	int	nbrs[4];

	i = 0;
	while (i < 4)
	{
		if (nbr % 10 < 1 || nbr % 10 > 4)
			return (0);
		nbrs[i++] = nbr % 10;
		nbr /= 10;
	}
	if (ft_is_duplicate(nbrs))
		return (0);
	return (1);
}

int	*ft_get_permutation(void)
{
	int	i;
	int	nbr;
	int	*permutations;

	i = 0;
	nbr = 1234;
	permutations = (int *) malloc(sizeof(int) * 24);
	if (permutations == NULL)
		return (NULL);
	while (nbr <= 4321)
	{
		if (ft_is_valid_nbr(nbr))
			permutations[i++] = nbr;
		nbr++;
	}
	return (permutations);
}
