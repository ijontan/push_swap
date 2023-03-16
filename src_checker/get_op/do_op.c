/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:29:28 by itan              #+#    #+#             */
/*   Updated: 2023/03/16 16:36:08 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_list **a, t_list **b, char *str, int *valid)
{
	if (!ft_strcmp(str, "pa\n"))
		return (pa(a, b));
	if (!ft_strcmp(str, "pb\n"))
		return (pb(a, b));
	if (!ft_strcmp(str, "sa\n"))
		return (sa(a));
	if (!ft_strcmp(str, "sb\n"))
		return (sb(b));
	if (!ft_strcmp(str, "ss\n"))
		return (ss(a, b));
	if (!ft_strcmp(str, "ra\n"))
		return (ra(a));
	if (!ft_strcmp(str, "rb\n"))
		return (rb(b));
	if (!ft_strcmp(str, "rr\n"))
		return (rr(a, b));
	if (!ft_strcmp(str, "rra\n"))
		return (rra(a));
	if (!ft_strcmp(str, "rrb\n"))
		return (rrb(b));
	if (!ft_strcmp(str, "rrr\n"))
		return (rrr(a, b));
	*valid = 0;
}
