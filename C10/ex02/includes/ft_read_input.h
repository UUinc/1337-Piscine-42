/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:43:39 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/16 18:16:42 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_INPUT_H
# define FT_READ_INPUT_H
# include <unistd.h>
# include "ft_stdlib.h"

int		ft_read_input(int nbr);
void	ft_write_input(char *buffer, int nbr, int size);

#endif