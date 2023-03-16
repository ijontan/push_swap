/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:57 by itan              #+#    #+#             */
/*   Updated: 2023/03/16 17:18:31 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	free_lst(t_list *lst)
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

static int	create_list(int ac, char **av, t_list **a)
{
	int	i;
	int	*lst;
	int	*content;

	i = 0;
	lst = ft_calloc(ac - 1, sizeof(int));
	while (++i < ac)
		lst[i - 1] = ft_atoi(av[i]);
	lst = indexing(lst, ac - 1);
	if (!lst)
		return (0);
	i = 0;
	while (i < ac - 1)
	{
		content = malloc(sizeof(int));
		*content = lst[i++];
		ft_lstadd_back(a, ft_lstnew(content));
	}
	free(lst);
	return (1);
}

int	main(int ac, char const **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	if (check_valid_input(ac, (char **)av))
		return (1);
	if (!create_list(ac, (char **)av, &a))
		return (1);
	if (ft_lstsize(a) == 2)
		q_sort_2(&a, &b, 1);
	else if (ft_lstsize(a) == 3)
		sort_3(&a, &b, 0);
	else if (ft_lstsize(a) == 4)
		q_sort_4(&a, &b, 1);
	else if (ft_lstsize(a) == 5)
		sort_5(&a, &b);
	else if (ft_lstsize(a) <= 150)
		sort_part(&a, &b);
	else
		quick_sort(&a, &b, ft_lstsize(a), 1);
	free_lst(a);
	free_lst(b);
	return (0);
}
