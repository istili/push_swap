/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:10:46 by istili            #+#    #+#             */
/*   Updated: 2024/03/23 21:14:03 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sign(const char *str, int i)
{
	int	sign;

	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	long	nb;
	long	tmp;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\r' 
		|| str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	sign = check_sign(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (ft_isdigit(str[i]))
	{
		tmp = nb * 10 + str[i] - '0';
		if (nb > tmp && sign == 1)
			return (-1);
		if (nb > tmp && sign == -1)
			return (0);
		nb = tmp;
		i++;
	}
	return (nb * sign);
}