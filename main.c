/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:18:02 by istili            #+#    #+#             */
/*   Updated: 2024/04/09 04:44:13 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	system("leaks a.out");
}

void	print_stack(t_stack **stack)
{
	t_node	*head;

	head = (*stack)->head;
	while (head)
	{
		printf("%d -> %d -> %d\n", head->data, head->count, head->act);
		head = head->next;
	}
}

int	check_double(t_stack **stack)
{
	t_node	*i;
	t_node	*j;

	i = (*stack)->head;
	while (i)
	{
		j = (*stack)->head;
		while (j)
		{
			if (i != j && i->data == j->data)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

static int	args(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**split_args;
	char	*arr;

	// atexit(f);
	i = 1;
	a = NULL;
	b = NULL;
	arr = NULL ;
	if (ac == 1)
		return (0);
	while (ac > i)
		arr = ft_strjoin(arr, av[i++]);
	split_args = ft_split(arr, ' ');
	free(arr);
	i = 0;
	while (split_args[i])
	{
		if (args(split_args[i]) == 0)
		{
			write(2, "Error1\n", 7);
			return (0);
		}
		i++;
	}
	if (split_args[0] == 0)
	{
		write(2, "Error2\n", 7);
		return (0);
	}
	a = stack_init(a, split_args);
	stack(&b);
	if (check_double(&a) == 0)
	{
		write(2, "Error3\n", 7);
		freee(a);
		return (0);
	}
/* 	puts("stack a:\n");
	print_stack(&a);
	puts("\n"); */
	if (!sorted(&a))
	{
		if (stack_len(&a) == 2)
			sa(&a);
		else if (stack_len(&a) == 3)
			easy(&a);
		else if (stack_len(&a) == 4)
			sort_for(&a, &b);
		else if (stack_len(&a) == 5)
			sort_fiv(&a, &b);
		else
			sort_stack(&a, &b);
	}
	/* puts("stack a:\n");
	print_stack(&a);
	puts("stack b:\n");
	print_stack(&b); */
	freee(b);
	freee(a);
}
