/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:02:37 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/09 11:11:15 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_str_char_twice(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_str_non_usable(char *str, int len)
{
	int	i;

	if (len < 2)
		return (1);
	i = 0;
	while (i < len)
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		if (str[i] < 32 || (unsigned char)str[i] > 126)
			return (1);
		i++;
	}
	if (ft_str_char_twice(str, len))
		return (1);
	return (0);
}

int	ft_find(char *base, char c)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (c == base[i])
			return (i);
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		r;
	int		result;
	long	base_len;

	base_len = ft_strlen(base);
	if (ft_str_non_usable(base, base_len))
		return (0);
	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str >= 32 && *str <= 126)
	{
		r = ft_find(base, *str++);
		if (r == -1)
			break ;
		result *= base_len;
		result += r;
	}
	return (result * sign);
}

int	main()
{
	printf("%d\n", ft_atoi_base("123", "0123456789ABCDEF"));

	return 0;
}