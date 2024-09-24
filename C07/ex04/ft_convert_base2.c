/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:30:47 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/12 19:39:41 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nbr_length(int nbr, char *base, int len)
{
	int				base_len;
	unsigned int	n;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		n = nbr * -1;
		len++;
	}
	else
		n = nbr;
	while (n >= (unsigned int)base_len)
	{
		n /= base_len;
		len++;
	}
	len++;
	return (len);
}

void	ft_putnbr_base(long nbr, char *base, char *nbr_from)
{
	int		i;
	int		base_len;
	int		nbr_from_len;

	base_len = ft_strlen(base);
	nbr_from_len = nbr_length(nbr, base, 0);
	i = 0;
	if (nbr < 0)
	{
		nbr_from[0] = '-';
		nbr *= -1;
		i = 1;
	}
	nbr_from_len--;
	while (nbr >= base_len)
	{
		nbr_from[nbr_from_len] = base[nbr % base_len];
		nbr /= base_len;
		nbr_from_len--;
	}
	if (nbr < base_len)
		nbr_from[i] = base[nbr];
}
