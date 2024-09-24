/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:47:31 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/07 17:54:56 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	size;

	if (max <= min)
		return (NULL);
	size = max - min + 1;
	arr = (int *) malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		arr[i] = i + min;
		i++;
	}
	return (arr);
}
