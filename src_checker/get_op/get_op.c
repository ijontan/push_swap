/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:21:08 by itan              #+#    #+#             */
/*   Updated: 2023/03/16 16:42:49 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_op(t_list **a, t_list **b, int *valid)
{
	char	*tmp;

	tmp = get_next_line(STDIN_FILENO);
	while (tmp)
	{
		do_op(a, b, tmp, valid);
		if (!*valid)
		{
			free(tmp);
			return ;
		}
		free(tmp);
		tmp = get_next_line(STDIN_FILENO);
	}
	*valid = 1;
}
