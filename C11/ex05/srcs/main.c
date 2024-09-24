/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:34:12 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/13 13:02:25 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_valid_op(char *str);
int		ft_calculate(int val1, int val2, char op);
void	ft_do_op(char **args, int (*f)(char*), int (*cal)(int, int, char));

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	ft_do_op(av, &ft_valid_op, &ft_calculate);
	return (0);
}
