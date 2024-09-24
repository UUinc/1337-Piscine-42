/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:51:55 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 14:09:16 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include "ft_stdio.h"

int		ft_is_number(char c);
int		ft_is_str_number(char *str);
void	ft_custom_error(char *program_name, char *file_name);
void	ft_custom_error_message(char *program_name, char *message, char *flag);
void	ft_custom_error_message_2(char *program_name, char *message,
			char *flag);

#endif