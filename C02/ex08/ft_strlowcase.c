/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:03:50 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/02 16:04:15 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_lowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_lowcase(str[i]);
		i++;
	}
	return (str);
}
