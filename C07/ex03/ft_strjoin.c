/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:31:24 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/07 23:55:27 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join(int size, char **strs, char *str, char *sep)
{
	int	i;
	int	len;
	int	sep_len;

	i = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		len = ft_strlen(*(strs + i));
		ft_strcat(str, *(strs + i));
		if (i != size - 1)
		{
			ft_strcat(str, sep);
		}
		i++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		sep_len;
	int		len;
	char	*str;

	if (size <= 0)
	{
		str = (char *) malloc(sizeof(char));
		return (str);
	}
	sep_len = ft_strlen(sep);
	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(*(strs + i));
		i++;
	}
	str = (char *) malloc(sizeof(char) * (len + sep_len * (size - 1)));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	str = ft_join(size, strs, str, sep);
	return (str);
}
