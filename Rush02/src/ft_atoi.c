/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:54:23 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/15 17:55:04 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned __int128	ft_atoi(char *str)
{
	int					i;
	int					m_sign;
	unsigned __int128	result;

	i = 0;
	result = 0;
	m_sign = 0;
	while (is_space(str[i]) && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			m_sign++;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		result = (result * 10) + (str[i++] - '0');
	if (str[i] == '.' || m_sign & 2
		|| (result == 0 && str[i - 1] > '0' && str[i - 1] <= '9'))
	{
		g_error = ATOI_ERROR;
		return (0);
	}
	return (result);
}
