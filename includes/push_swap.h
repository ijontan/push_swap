/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:50:29 by itan              #+#    #+#             */
/*   Updated: 2023/02/07 16:17:36 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	quick_sort(t_list *a, t_list *b, int *count);

/* ---------------------------------- sort ---------------------------------- */
void	radix_sort_ps(t_list **a, t_list **b, int *count, int size);
void	merge_sort_ps(t_list **a, t_list **b, int *count, int num);

/* ------------------------------- operations ------------------------------- */
void	pa(t_list **a, t_list **b, int *count);
void	pb(t_list **a, t_list **b, int *count);

void	rotate(t_list **list, unsigned char reversed);

void	ra(t_list **a, int *count);
void	rb(t_list **b, int *count);
void	rr(t_list **a, t_list **b, int *count);

void	rra(t_list **a, int *count);
void	rrb(t_list **b, int *count);
void	rrr(t_list **a, t_list **b, int *count);

void	sa(t_list **a, int *count);
void	sb(t_list **b, int *count);

/* ---------------------------------- math ---------------------------------- */
int		power(int num, int power);
int		ft_log2(int num);

#endif