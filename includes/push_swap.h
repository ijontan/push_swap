/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:50:29 by itan              #+#    #+#             */
/*   Updated: 2023/02/09 17:36:04 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	quick_sort(t_list **a, t_list **b, int top_len, int bot_len);

/* ---------------------------------- sort ---------------------------------- */
void	radix_sort_ps(t_list **a, t_list **b, int size);
void	merge_sort_ps(t_list **a, t_list **b, int num);
void	sort_3(t_list **a);
void	sort_5(t_list **a, t_list **b);

/* ------------------------------- operations ------------------------------- */
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	rotate(t_list **list, unsigned char reversed);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sa(t_list **a);
void	sb(t_list **b);

/* ---------------------------------- math ---------------------------------- */
int		power(int num, int power);
int		ft_log2(int num);

/* ----------------------------------- put ---------------------------------- */
void	print(t_list *lst);

#endif