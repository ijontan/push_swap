/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:31:03 by itan              #+#    #+#             */
/*   Updated: 2023/03/16 17:23:19 by itan             ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		valid;

	b = NULL;
	a = NULL;
	valid = 1;
	if (check_valid_input(ac, av))
		return (ft_printf("%sERROR%s\n", "\033[1;31m", "\033[0m"));
	if (!create_list(ac, (char **)av, &a))
		return (ft_printf("%sERROR%s\n", "\033[1;31m", "\033[0m"));
	get_op(&a, &b, &valid);
	if (check_sorted(&a, &b) == -1 || !valid)
		ft_printf("%sERROR%s\n", "\033[1;31m", "\033[0m");
	else if (check_sorted(&a, &b) == 1)
		ft_printf("%sOK%s\n", "\033[1;32m", "\033[0m");
	else
		ft_printf("%sKO%s\n", "\033[1;31m", "\033[0m");
	free_lst(a);
	free_lst(b);
	return (0);
}
