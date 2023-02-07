/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:05:48 by itan              #+#    #+#             */
/*   Updated: 2023/02/07 17:48:55 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr");
}

void	rrr(t_list **a, t_list **b)
{
	rotate(a, 1);
	rotate(b, 1);
	ft_printf("rrr");
}
