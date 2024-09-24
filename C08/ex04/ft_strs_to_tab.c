/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:01:12 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/11 16:49:55 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*new_str;

	size = ft_strlen(src);
	new_str = (char *) malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_add_to_tab(int i, struct s_stock_str **stock, char *str)
{
	(*stock + i)->size = ft_strlen(str);
	(*stock + i)->str = str;
	(*stock + i)->copy = ft_strdup(str);
	if ((*stock + i)->copy == NULL)
		return (0);
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab;

	ac++;
	tab = (struct s_stock_str *) malloc(sizeof(struct s_stock_str) * ac);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		if (ft_add_to_tab(i, &tab, av[i]) == 0)
			return (NULL);
		i++;
	}
	(tab + i)->str = 0;
	(tab + i)->copy = 0;
	return (tab);
}
