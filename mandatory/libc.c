/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:16:42 by istili            #+#    #+#             */
/*   Updated: 2024/06/04 14:36:28 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	stack(t_stack **b)
{
	*b = malloc(sizeof(t_stack));
	if (!(*b))
		ft_puterror();
	(*b)->head = NULL;
	(*b)->tail = NULL;
}

int	stack_len(t_stack **stack)
{
	int		count;
	t_node	*head;

	if ((*stack)->head == NULL)
		return (0);
	head = (*stack)->head;
	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	slen;

	x = 0;
	slen = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[x] && x < (dstsize - 1))
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = 0;
	}
	return (slen);
}

char	*ft_strjoin(char *line, char *bufr)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = (char *)malloc(ft_strlen(line) + ft_strlen(bufr) + 2);
	if (!s)
		return ((free(line)), NULL);
	i = 0;
	while (line != NULL && line[i] != '\0')
	{
		s[i] = line[i];
		i++;
	}
	j = -1;
	s[i++] = ' ';
	while (bufr != 0 && bufr[++j] != '\0')
		s[i + j] = bufr[j];
	s[i + j] = '\0';
	if (line)
		free(line);
	return (s);
}
