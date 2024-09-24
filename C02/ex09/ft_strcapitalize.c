/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:04:24 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/02 16:29:22 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_upcase(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	ft_lowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_is_alphanumeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str[0] = ft_upcase(str[0]);
	i = 1;
	while (str[i])
	{
		str[i] = ft_lowcase(str[i]);
		if (!ft_is_alphanumeric(str[i - 1]))
			str[i] = ft_upcase(str[i]);
		i++;
	}
	return (str);
}
