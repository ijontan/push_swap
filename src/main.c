/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:57 by itan              #+#    #+#             */
/*   Updated: 2023/02/07 16:20:06 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(void *content)
{
	ft_printf("%i, ", *(int *)content);
}

int	main(int ac, char const **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		*content;
	int		count;

	count = 0;
	i = 0;
	b = (t_list *)malloc(sizeof(t_list));
	while (i < ac - 1)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(av[++i]);
		ft_lstadd_back(&a, ft_lstnew(content));
	}
	// radix_sort_ps(&a, &b, &count, ft_lstsize(a));
	quick_sort(a, b, &count);
	ft_printf("a:  ");
	ft_lstiter(a, &put);
	ft_printf("\nb:  ");
	ft_lstiter(b, &put);
	ft_printf("\n");
	ft_printf("count:  %i\n", count);
	return (0);
}
