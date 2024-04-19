/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:18:02 by istili            #+#    #+#             */
/*   Updated: 2024/04/19 18:08:02 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_digit(long n)
{
	int res = 0;

	if (n < 0)
	{
		n = -n;
		res++;
	}
	if (n == 0)
		return 1;
	while (n > 0) 
	{
		n /= 10;
		res++;
	}
	return res;
}

char	*ft_itoa(int nbr)
{
	long n = (long)nbr;
	int size = count_digit(n);
	char	*res = malloc(size + 1);
	int i = size;
	if (!res)
		return 0;
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return res;
	}
	res[i] = '\0';
	i--;
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return res;
}
#include "string.h"
void	f(void)
{
	// int	pid = getpid();
	// char	*str = strdup("leaks ");
	// char *str2 = ft_strjoin(str, ft_itoa(pid));
	// system(str2);
	system("leaks push_swap");
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

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int		is_full_space(char *str)
{
	while (*str == '\t' || *str == ' ')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
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
		if (av[i][0] == '\0' || is_full_space(av[i]))
		{
			free(arr);
			return (0);
		}
		arr = ft_strjoin(arr, av[i++]);
	}
	split_args = ft_split(arr, ' ');
	free(arr);
	i = 0;
	while (split_args[i])
	{
		if (args(split_args[i]) == 0)
		{
			write(2, "Error1\n", 6);
			free_array(split_args);
			return (0);
		}
		i++;
	}
	if (split_args[0] == 0)
	{
		write(2, "Error2\n", 6);
		// free(split_args);
		return (0);
	}
	a = stack_init(a, split_args);
	stack(&b);
	if (check_double(&a) == 0)
	{
		write(2, "Error3\n", 6);
		free(b);
		freee(a);
		return (0);
	}
	// free_array(split_args);
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
	freee(b);
	freee(a);
}
