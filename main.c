/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:18:02 by istili            #+#    #+#             */
/*   Updated: 2024/04/02 20:53:01 by istili           ###   ########.fr       */
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
		printf("%d\n", head->data);
		head = head->next;
	}
}

static int	args(char *s)
{
	int	i;

	i = 0;
	while ((s[i] >= '0' && s[i] <= '9')
		|| (s[i] == '-' || s[i] == '+') || s[i] == ' ')
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

	atexit(f);
	i = 1;
	a = NULL;
	b = NULL;
	arr = NULL ;
	if (ac == 1)
		return (0);
	while (ac > i)
	{
		if (args(av[i]) == 0)
		{
			if (arr != NULL)
				free(arr);
			puts("no can't do");
			return (0);
		}
		arr = ft_strjoin(arr, av[i++]);
	}
	split_args = ft_split(arr, ' ');
	free(arr);
	a = stack_init(a, split_args);
	stack(&b);
	puts("stack a:\n");
	print_stack(&a);
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
	puts("stack a:\n");
	print_stack(&a);
	puts("stack b:\n");
	print_stack(&b);
	freee(b);
	freee(a);
}
// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		i;
// 	a = NULL;
// 	b = NULL;
// 	i = 1;
// 	if (ac > i && args(av[i++]) != -1)
// 	// if ((ac == 2) && ((int)av[i++] != ' ' || (int)av[i++] != '+' || (int)av[i++] != '-'))
// 	// {
// 	// 	printf("%s\n", "wrong args !!");
// 	// 	exit (0);	
// 	// }
// 	if (ac == 2)
// 		av = ft_split(av[1], ' ');
// 	a = stack_init(a, av + 1);
// 	check(&a);
// 	// stack(&b);
// 	puts("stack a:\n");
// 	print_stack(&a);
// 	easy(&a);
// 	// pb(&a, &b);
// 	// pb(&a, &b);
// 	// sa(&a);
// 	// ra(&a);
// 	// pa(&a, &b);
// 	// ra(&a);
// 	// pa(&a, &b);
// 	puts("stack a:\n");
// 	print_stack(&a);
// 	// puts("stack b:\n");
// 	// print_stack(&b);
// 	// easy2(&a, &b);
// 	// if (!sorted(a))
// 	// {
// 	// 	if (stack_len(&a) == 2)
// 	// 		sa(&a);
// 	// 	else if (stack_len(a) == 3)
// 	// 		easy(&a);
// 	// }
// }
