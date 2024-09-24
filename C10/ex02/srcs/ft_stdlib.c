/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:21:36 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/16 15:55:51 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

char	*realloc_str(char *str, unsigned int add_size)
{
	unsigned int	new_size;
	char			*new_str;

	new_size = ft_strlen(str);
	new_size += add_size + 1;
	new_str = (char *)malloc(sizeof(char) * new_size);
	if (new_str == NULL)
		return (NULL);
	new_str = ft_strcpy(new_str, str);
	free(str);
	return (new_str);
}
