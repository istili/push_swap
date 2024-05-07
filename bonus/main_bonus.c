/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:00:27 by istili            #+#    #+#             */
/*   Updated: 2024/05/07 19:13:45 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	main_checks(char **split_args)
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

static void	main_helper(t_stack **a, t_stack **b, char **split_args)
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

static void	init_args(int *i, t_stack **a, t_stack **b, char **arr)
{
	*i = 1;
	*a = NULL;
	*b = NULL;
	*arr = NULL;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**split_args;
	char	*arr;

	init_args(&i, &a, &b, &arr);
	if (ac == 1)
		return (0);
	while (ac > i)
	{
		if (av[i][0] == '\0' || is_full_space(av[i]))
		{
			free(arr);
			ft_puterror();
		}
		arr = ft_strjoin(arr, av[i++]);
	}
	split_args = ft_split(arr, ' ');
	free(arr);
	main_checks(split_args);
	main_helper(&a, &b, split_args);
	freee(a);
	freee(b);
}
