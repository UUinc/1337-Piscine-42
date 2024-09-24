/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:56:41 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/02 16:03:15 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_upcase(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_upcase(str[i]);
		i++;
	}
	return (str);
}
