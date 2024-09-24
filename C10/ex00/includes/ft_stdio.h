/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:30:27 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 13:32:26 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H
# include <unistd.h>

void	ft_print_to_fd(char *str, int fd);
void	ft_print_buffer(char *str, int size);
void	ft_print(char *str);
void	ft_print_line(char *str);
void	ft_print_error(char *str);

#endif