/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:57 by itan              #+#    #+#             */
/*   Updated: 2023/02/13 19:25:12 by itan             ###   ########.fr       */
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

int	main(int ac, char const **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		*content;

	i = 0;
	b = NULL;
	a = NULL;
	while (i < ac - 1)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(av[++i]);
		ft_lstadd_back(&a, ft_lstnew(content));
	}
	// radix_sort_ps(&a, &b, &count, ft_lstsize(a));
	if (ft_lstsize(a) == 3)
		sort_3(&a);
	// else if (ft_lstsize(a) == 5)
	// 	sort_5(&a, &b);
	else
		quick_sort(&a, &b, ft_lstsize(a), 1);
	// ft_printf("a:  ");
	// ft_lstiter(a, &put);
	// ft_printf("\nb:  ");
	// ft_lstiter(b, &put);
	// ft_printf("\n");
	return (0);
}
