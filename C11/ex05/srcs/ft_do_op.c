/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:48:04 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/13 13:08:23 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	ft_div_zero(int val2, char op)
{
	if (val2 == 0 && op == '/')
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (val2 == 0 && op == '%')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

void	ft_do_op(char **args, int (*f)(char*), int (*cal)(int, int, char))
{
	int		val1;
	int		val2;
	int		res;
	char	op;

	op = f(args[2]);
	if (op == 0)
	{
		write(1, "0\n", 2);
		return ;
	}
	val1 = ft_atoi(args[1]);
	val2 = ft_atoi(args[3]);
	if (ft_div_zero(val2, op))
		return ;
	res = cal(val1, val2, op);
	ft_putnbr(res);
	write(1, "\n", 1);
}
