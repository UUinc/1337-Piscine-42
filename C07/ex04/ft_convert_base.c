/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:30:40 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/12 20:13:23 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base(long nbr, char *base, char *nbrf);
int		nbr_length(int nbr, char *base, int lenght);

int	is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)
			|| str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	nbr_base(char str, char *base)
{
	int	nb;

	nb = 0;
	while (base[nb])
	{
		if (str == base[nb])
			return (nb);
		nb++;
	}
	return (-1);
}

int	whitespaces(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	count;
	int	nb;
	int	nb2;
	int	base_lenght;

	nb = 0;
	i = 0;
	base_lenght = is_valid(base);
	if (base_lenght >= 2)
	{
		count = whitespaces(str, &i);
		nb2 = nbr_base(str[i], base);
		while (nb2 != -1)
		{
			nb = (nb * base_lenght) + nb2;
			i++;
			nb2 = nbr_base(str[i], base);
		}
		return (nb *= count);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*finalnbr;
	int		mednbr;
	int		lenght_nbrf;

	if (is_valid(base_to) == 0 || is_valid(base_from) == 0)
		return (0);
	mednbr = ft_atoi_base(nbr, base_from);
	lenght_nbrf = nbr_length(mednbr, base_to, 0);
	finalnbr = (char *) malloc(sizeof(char) * (lenght_nbrf + 1));
	if (finalnbr == NULL)
		return (0);
	ft_putnbr_base(mednbr, base_to, finalnbr);
	finalnbr[lenght_nbrf] = '\0';
	return (finalnbr);
}
