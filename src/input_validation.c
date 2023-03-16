/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:49:23 by itan              #+#    #+#             */
/*   Updated: 2023/03/16 16:03:53 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_valid_number(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_valid_input(int ac, char **av)
{
	int	lst_len;

	lst_len = 0;
	while (av[lst_len + 1] && check_valid_number(av[lst_len + 1]))
		lst_len++;
	if (lst_len + 1 != ac)
		return (1);
	return (0);
}
