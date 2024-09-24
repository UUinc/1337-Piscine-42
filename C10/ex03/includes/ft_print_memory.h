/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:37:29 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 14:20:32 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_MEMORY_H
# define FT_PRINT_MEMORY_H
# include <unistd.h>
# include "ft_string.h"

int		g_flag;
char	g_last_str[17];

int				ft_handle_dub(char *str, unsigned int *i);
void			ft_print_sep(char *str, unsigned int nbr, int option);
void			ft_print_address(char *addr_buff, unsigned i,
					unsigned ln, int opt);
void			ft_print_data(char *str, unsigned int nbr, int opt);
void			ft_print_str(char *str, unsigned int size, unsigned int start);
void			ft_print_hexa(char *addr_buff, long addr_value);
void			ft_print_str_hexa(char *str, unsigned int size, int opt);
unsigned int	ft_print_memory(void *addr, unsigned int size,
					unsigned int line, int opt);
unsigned int	ft_print_memory_rest(void *addr, unsigned int size,
					unsigned int line, int opt);

#endif