/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:18:02 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 11:48:51 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	// int	pid = getpid();
	// char	*str = strdup("leaks ");
	// char *str2 = ft_strjoin(str, ft_itoa(pid));
	// system(str2);
	system("leaks push_swap");
}

void	main_sort(t_stack **a, t_stack **b)
{
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) == 3)
			easy(a);
		else if (stack_len(a) == 4)
			sort_for(a, b);
		else if (stack_len(a) == 5)
			sort_fiv(a, b);
		else
			sort_stack(a, b);
	}
}

void	main_checks(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		if (args(split_args[i]) == 0)
		{
			write(2, "Error\n", 6);
			free_array(split_args);
			exit(1);
		}
		i++;
	}
	if (split_args[0] == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	main_helper(t_stack **a, t_stack **b, char **split_args)
{
	*a = stack_init(*a, split_args);
	stack(b);
	if (check_double(a) == 0)
	{
		write(2, "Error\n", 6);
		free(b);
		freee(*a);
		exit(1);
	}
}

void	init__main_args(int *i, t_stack **a, t_stack **b, char **arr)
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

	init__main_args(&i, &a, &b, &arr);
	if (ac == 1)
		return (0);
	while (ac > i)
	{
		if (av[i][0] == '\0' || is_full_space(av[i]))
		{
			write(2, "Error\n", 6);
			free(arr);
			return (0);
		}
		arr = ft_strjoin(arr, av[i++]);
	}
	split_args = ft_split(arr, ' ');
	free(arr);
	main_checks(split_args);
	main_helper(&a, &b, split_args);
	main_sort(&a, &b);
	freee(b);
	freee(a);
}
