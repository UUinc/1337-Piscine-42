/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_handling.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:47:48 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/16 17:52:27 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_HANDLING_H
# define FT_FILE_HANDLING_H
# include <unistd.h>
# include <fcntl.h>
# include "ft_string.h"

int	ft_fopen(char *file_name, char *open_mode);
int	ft_fclose(int fd);
int	ft_fread(int fd, char *buffer, unsigned int size);
int	ft_fwrite(int fd, char *buffer, unsigned int size);
int	ft_size(char *file_name);

#endif