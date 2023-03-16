/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:50:29 by itan              #+#    #+#             */
/*   Updated: 2023/03/16 16:48:49 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_insertion
{
	int	len_top;
	int	len_bot;
	int	biggest_num;
}		t_insertion;

int		*indexing(int *a, int len);
int		check_valid_input(int ac, char **av);
int		check_sorted(t_list **a, t_list **b);

void	quick_sort(t_list **a, t_list **b, int len, int at_a);
void	q_sort_2(t_list **a, t_list **b, int at_a);
void	q_sort_4(t_list **a, t_list **b, int at_a);
void	q_sort_3(t_list **a, t_list **b, int s_sb);
void	q_sort_5(t_list **a, t_list **b);
int		find_average_of_part(t_list *lst, int len);
/* ---------------------------------- sort ---------------------------------- */
void	insertion_sort(t_list **a, t_list **b, int len, int at_a);
int		get_biggest_val(t_list *list, int len_top, int len_bot);
void	sort_part(t_list **a, t_list **b);
void	radix_sort_ps(t_list **a, t_list **b, int size);
void	merge_sort_ps(t_list **a, t_list **b, int num);
void	sort_3(t_list **a, t_list **b, int s_sb);
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
void	ss(t_list **a, t_list **b);

/* ---------------------------------- math ---------------------------------- */
int		power(int num, int power);
int		ft_log2(int num);
int		find_average_of_part(t_list *lst, int len);

/* ----------------------------------- put ---------------------------------- */
void	print(t_list *lst);
/* ---------------------------------- do_op --------------------------------- */
void	get_op(t_list **a, t_list **b, int *valid);
void	do_op(t_list **a, t_list **b, char *str, int *valid);

#endif