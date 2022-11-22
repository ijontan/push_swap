/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:50:29 by itan              #+#    #+#             */
/*   Updated: 2022/11/22 17:31:10 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	quick_sort(int *lst, ssize_t lo, ssize_t hi);

/* ---------------------------------- sort ---------------------------------- */
void	radix_sort_ps(t_list **a, t_list **b, int *count, int size);

/* ------------------------------- operations ------------------------------- */
void	pa(t_list **a, t_list **b, int *count);
void	pb(t_list **a, t_list **b, int *count);

void	ra(t_list **a, int *count);
void	rb(t_list **b, int *count);

void	rra(t_list **a, int *count);
void	rrb(t_list **b, int *count);

void	sa(t_list **a, int *count);
void	sb(t_list **b, int *count);

void	merge_sort_ps(t_list **a, t_list **b, int *count, int num);
#endif