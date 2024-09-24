/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:10:58 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 12:53:43 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H
# include "ft_stdlib.h"
# include "ft_string.h"
# include "ft_print_memory.h"

unsigned int	g_line_c;

char	*ft_print_hexdump(char *buffer, int option);

#endif