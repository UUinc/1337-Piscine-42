/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:34:22 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 15:11:16 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_FILE_H
# define FT_READ_FILE_H
# include "ft_string.h"
# include "ft_file_handling.h"
# include "ft_utils.h"
# include "ft_hexdump.h"

int	ft_read_files(int argc, char **argv, int index, int option);

#endif