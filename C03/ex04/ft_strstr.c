/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:53:30 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/04 14:51:21 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	str_len;
	int	find_len;

	str_len = ft_strlen(str);
	find_len = ft_strlen(to_find);
	if (find_len == 0)
		return (str);
	i = 0;
	while (i <= str_len - find_len)
	{
		if (ft_strncmp(str + i, to_find, find_len) == 0)
			return (str + i);
		i++;
	}
	return ((void *)0);
}
