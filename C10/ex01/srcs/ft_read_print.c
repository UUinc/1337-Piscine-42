/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:43:41 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/16 16:07:37 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_print.h"

int	ft_read_print(void)
{
	char	c;
	int		error;

	while (1)
	{
		error = read(0, &c, 1);
		if (error <= 0)
			break ;
		write(1, &c, 1);
	}
	return (error);
}
