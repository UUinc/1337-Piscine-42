/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:41:32 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/15 17:47:47 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*new_str;

	size = ft_strlen(src);
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
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

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_len;
	unsigned int	dest_len;
	char			*new_dest;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	new_dest = (char *)malloc(sizeof(char) * (src_len + dest_len + 1));
	i = 0;
	while (dest[i])
	{
		new_dest[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j])
		new_dest[i++] = src[j++];
	new_dest[i] = '\0';
	return (new_dest);
}

char	*ft_tricat(char *dest, char *src1, char *src2)
{
	dest = ft_strcat(dest, src1);
	dest = ft_strcat(dest, src2);
	return (dest);
}

char	*ft_fourcat(char *dest, char *src1, char *src2, char *src3)
{
	dest = ft_strcat(dest, src1);
	dest = ft_strcat(dest, src2);
	dest = ft_strcat(dest, src3);
	return (dest);
}
