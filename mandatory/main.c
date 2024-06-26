/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:18:02 by istili            #+#    #+#             */
/*   Updated: 2024/06/04 14:54:47 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;
	char	*arr;

	a = NULL;
	b = NULL;
	arr = NULL;
	split_args = NULL;
	helper(ac, av, &arr);
	split_args = ft_split(arr, ' ');
	if (!split_args)
		ft_puterror();
	free(arr);
	main_helper(&a, &b, split_args);
	sort(&a, &b);
	freee(b);
	freee(a);
}
