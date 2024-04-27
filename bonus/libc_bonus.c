/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:29:51 by istili            #+#    #+#             */
/*   Updated: 2024/04/26 11:33:26 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
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
	while (bufr != 0 && bufr[++j] != '\0' && bufr[j] != '\n')
		s[i + j] = bufr[j];
	if (bufr != 0 && bufr[j] == '\n')
		s[i + j++] = '\n';
	s[i + j] = '\0';
	if (line)
		free(line);
	return (s);
}
