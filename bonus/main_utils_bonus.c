/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:39:18 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 17:40:00 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	main_checks(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		if (args(split_args[i]) == 0)
		{
			free_arr(split_args);
			ft_puterror();
		}
		i++;
	}
	if (split_args[0] == 0)
		ft_puterror();
}

void	main_helper(t_stack **a, t_stack **b, char **split_args)
{
	char	*line;

	*a = stack_init(*a, split_args);
	stack(b);
	if (check_double(a) == 0)
	{
		freee(*b);
		freee(*a);
		ft_puterror();
	}
	line = get_next_line(0);
	while (line)
	{
		ft_cmp(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (sorted(a) && stack_len(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	helper(int ac, char **av, char **split_args, char **arr)
{
	int	i;

	i = 1;
	if (ac == 1)
		ft_puterror();
	while (ac > i)
	{
		if (av[i][0] == '\0' || is_full_space(av[i]))
		{
			free(arr);
			ft_puterror();
		}
		*arr = ft_strjoin(*arr, av[i++]);
		if (!*arr)
			ft_puterror();
	}
	split_args = ft_split(*arr, ' ');
	if (!split_args)
		ft_puterror();
}
