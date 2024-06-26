/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:00:27 by istili            #+#    #+#             */
/*   Updated: 2024/06/04 16:13:28 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;
	char	*arr;

	a = NULL;
	b = NULL;
	arr = NULL;
	split_args = helper(ac, av, &arr);
	free(arr);
	main_checks(split_args);
	main_helper(&a, &b, split_args);
	freee(a);
	freee(b);
}
