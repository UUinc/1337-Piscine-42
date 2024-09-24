/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:09:44 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/08 14:29:51 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_input_checker(char *input_str, int	*input)
{
	int	i;
	int	j;
	int	f;

	i = -1;
	j = 0;
	f = 1;
	while (input_str[++i])
	{
		if (input_str[i] == ' ')
		{
			f = 1;
			continue ;
		}
		if (input_str[i] >= '1' && input_str[i] <= '4' && f)
		{
			input[j++] = input_str[i] - '0';
			f = 0;
			continue ;
		}
		return (NULL);
	}
	if (j != 16)
		return (NULL);
	return (input);
}

int	*ft_input(char *input_str)
{
	int	*input;

	input = (int *) malloc(sizeof(int) * 16);
	input = ft_input_checker(input_str, input);
	return (input);
}
