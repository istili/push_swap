/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:11:49 by istili            #+#    #+#             */
/*   Updated: 2024/06/04 14:40:45 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	main_helper(t_stack **a, t_stack **b, char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		if (args(split_args[i]) == 0)
		{
			free_array(split_args);
			ft_puterror();
		}
		i++;
	}
	if (split_args[0] == 0)
		ft_puterror();
	*a = stack_init(*a, split_args);
	if (!*a)
		ft_puterror();
	stack(b);
	if (check_double(a) == 0)
	{
		freee(*b);
		freee(*a);
		ft_puterror();
	}
}

void	helper(int ac, char **av, char **arr)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(0);
	while (ac > i)
	{
		if (av[i][0] == '\0' || is_full_space(av[i]))
		{
			if (*arr)
				free(*arr);
			ft_puterror();
		}
		*arr = ft_strjoin(*arr, av[i++]);
		if (!*arr)
			ft_puterror();
	}
}
