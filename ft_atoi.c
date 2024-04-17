/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:10:46 by istili            #+#    #+#             */
/*   Updated: 2024/04/17 16:44:42 by istili           ###   ########.fr       */
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
	int		sign;
	int		i;
	long	int_min;

	i = 0;
	sign = 1;
	int_min = INT_MAX;
	int_min++;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	sign = check_sign(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		if (nb > INT_MAX && sign == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (nb > int_min && sign == -1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (nb * sign);
}
