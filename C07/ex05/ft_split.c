/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:19:03 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/09 14:22:47 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find_sep(char *seps, char sep)
{
	int	i;

	i = 0;
	while (seps[i])
	{
		if (seps[i] == sep)
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_len(char *str, char *seps)
{
	unsigned int	i;

	i = 0;
	while (str[i] && !ft_find_sep(seps, str[i]))
		i++;
	return (i);
}

int	ft_count_words(char *str, char *seps)
{
	int	i;
	int	c;
	int	f;

	c = 0;
	f = 1;
	i = -1;
	while (str[++i])
	{
		if (ft_find_sep(seps, str[i]))
		{
			f = 1;
			continue ;
		}
		if (f)
		{
			f = 0;
			c++;
		}
	}
	return (c);
}

int	ft_get_word(char *str, char *seps, int start)
{
	int	i;

	i = start - 1;
	while (str[++i])
	{
		if (ft_find_sep(seps, str[i]))
			continue ;
		return (i);
	}
	return (-1);
}

char	**ft_split(char *str, char *charset)
{
	int		i[3];
	int		words;
	char	**strs;
	int		start;
	int		len;

	words = ft_count_words(str, charset) + 1;
	strs = (char **) malloc(sizeof(char *) * words);
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] && i[1] < words)
	{
		start = ft_get_word(str, charset, i[0]);
		len = ft_word_len(str + start, charset) + 1;
		*(strs + i[1]) = (char *) malloc(sizeof(char) * len);
		i[2] = -1;
		while (++i[2] < len - 1)
			*(*(strs + i[1]) + i[2]) = *(str + start + i[2]);
		*(*(strs + i[1]) + i[2]) = '\0';
		i[1]++;
		i[0] = start + len;
	}
	*(strs + words - 1) = (char *){0};
	return (strs);
}
