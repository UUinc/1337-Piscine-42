/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:40:29 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/16 17:54:25 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include "ft_stdio.h"
# include "ft_utils.h"
# include "ft_file_handling.h"
# include "ft_read_input.h"

int	ft_tail_file(char *file_name, int nbr);
int	ft_tail_files(int argc, char **argv, int index, int nbr);

#endif
