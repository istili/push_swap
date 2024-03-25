/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:15:43 by istili            #+#    #+#             */
/*   Updated: 2024/03/23 22:36:16 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(t_stack **stack) // ./a.out 2 2 1
{
	t_node	*head;

	head = (*stack)->head;
	while (head && head->next)
	{
		if (head->data == head->next->data)
		{
			write(1, "sorry can't do\n", 15);
			exit(1);
			return ;
		}
		head = head->next;
	}
}

// int	check_doubl(const char *arr)
// {
	
// }

int	args(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9')
			|| (s[i] == '-' || s[i] == '+') || s[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (1);
}

// static int	is_number(t_stack **stack)
// {
// 	int	i = 0;

// 	while (*stack && (*stack)->head)
// 	{
// 		if ((*stack)->head->data >= '0' && (*stack)->head->data >= '9'
// 			|| (*stack)->head->data == '-' && (*stack)->head->data == '+')
// 		{
// 			(*stack)->head = (*stack)->head->next;
// 		}
// 		return (1);
// 		print_stack(stack);
// 		puts("stack dyali :\n");
// 		printf("1");
// 	}
// 	return (0);
// 	printf("0");
// }