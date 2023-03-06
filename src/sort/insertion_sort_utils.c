/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:24:49 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 14:30:13 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_if_bigger(t_list **list, int *num, int *sign, int rs)
{
	if (*num < *((int *)((*list)->content)))
	{
		*num = *((int *)((*list)->content));
		*sign = rs;
	}
	*list = (*list)->next;
}

static void	set_val(t_list *list, int *len_top, int *len_bot)
{
	*len_top = ft_lstsize(list) / 2 + ft_lstsize(list) % 2;
	*len_bot = ft_lstsize(list) / 2;
}

int	get_biggest_val(t_list *list, int len_top, int len_bot)
{
	int	num;
	int	i;
	int	mid_len;
	int	sign;

	sign = 1;
	mid_len = ft_lstsize(list) - len_top - len_bot;
	num = *((int *)(list->content));
	i = 0;
	if (mid_len == 0)
		set_val(list, &len_top, &len_bot);
	while (i++ < len_top)
		check_if_bigger(&list, &num, &sign, 1);
	i = 0;
	while (i++ < mid_len)
		list = list->next;
	i = 0;
	while (i++ < len_bot)
		check_if_bigger(&list, &num, &sign, -1);
	return (num * sign);
}
