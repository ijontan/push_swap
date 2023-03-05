/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:57 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 06:08:32 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(void *content)
{
	ft_printf("%i, ", *(int *)content);
}

void	print(t_list *lst)
{
	if (!lst)
		return (void)(ft_printf("null\n"));
	while (lst)
	{
		put(lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	print_both(t_list *a, t_list *b)
{
	ft_printf("a\tb\t\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%i\t", *(int *)a->content);
			a = a->next;
		}
		else
			ft_printf("\t");
		if (b)
		{
			ft_printf("%i\t", *(int *)b->content);
			b = b->next;
		}
		ft_printf("\n");
	}
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
}

void	printlst(int *lst, int len)
{
	int	i;

	i = 0;
	while (i < len)
		ft_printf("%i, \n", lst[i++]);
}

int	main(int ac, char const **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		*content;
	int		*lst;

	i = 0;
	b = NULL;
	a = NULL;
	lst = ft_calloc(ac - 1, sizeof(int));
	while (++i < ac)
		lst[i - 1] = ft_atoi(av[i]);
	lst = indexing(lst, ac - 1);
	i = 0;
	while (i < ac - 1)
	{
		content = malloc(sizeof(int));
		*content = lst[i++];
		ft_lstadd_back(&a, ft_lstnew(content));
	}
	free(lst);
	if (ft_lstsize(a) == 3)
		sort_3(&a);
	else if (ft_lstsize(a) <= 150)
		sort_part(&a, &b);
	// else if (ft_lstsize(a) == 5)
	// 	sort_5(&a, &b);
	else
		// insertion_sort(&a, &b, ac - 1, 1);
		quick_sort(&a, &b, ft_lstsize(a), 1);
	free_lst(a);
	free_lst(b);
	return (0);
}
