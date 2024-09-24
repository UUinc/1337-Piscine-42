/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:21:40 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 09:49:21 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H
# include <stdlib.h>
# include "ft_string.h"

char	*realloc_str(char *str, unsigned int add_size);
char	*dealloc_str(char *str, unsigned int sub_size);

#endif