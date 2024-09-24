/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:39:46 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/13 13:08:39 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_valid_op(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len != 1)
		return (0);
	if (str[0] == '+' || str[0] == '-' || str[0] == '/'
		|| str[0] == '*' || str[0] == '%')
	{
		return (str[0]);
	}
	return (0);
}

int	ft_calculate(int val1, int val2, char op)
{
	if (op == '+')
		return (val1 + val2);
	if (op == '-')
		return (val1 - val2);
	if (op == '/')
		return (val1 / val2);
	if (op == '*')
		return (val1 * val2);
	if (op == '%')
		return (val1 % val2);
	return (-1);
}
