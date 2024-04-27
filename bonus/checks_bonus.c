/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:10:48 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 11:08:23 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
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

int	is_full_space(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s)
		return (0);
	return (1);
}

int	args(char *s)
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

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
