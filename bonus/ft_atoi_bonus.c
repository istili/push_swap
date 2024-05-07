/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:45:45 by istili            #+#    #+#             */
/*   Updated: 2024/05/07 19:18:25 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*ft_fre(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

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

static void	spaces(char **str)
{
	while (**str == '\t' || **str == '\f' || **str == '\r'
		|| **str == '\v' || **str == '\n' || **str == ' ')
		(*str)++;
}

int	ft_atoi(char *str)
{
	long	nb;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	spaces(&str);
	sign = check_sign(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i++] - '0';
		if ((nb > INT_MAX && sign == 1)
			|| (nb > -(long)(INT_MIN) && sign == -1))
			ft_puterror();
	}
	return (nb * sign);
}
