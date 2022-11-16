/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:57 by itan              #+#    #+#             */
/*   Updated: 2022/11/16 21:11:12 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(void *content)
{
	ft_printf("%i\n", *(int *)content);
}

int	main(int ac, char const **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		*content;
	int		count;

	count = 0;
	(void)b;
	i = 0;
	while (i < ac - 1)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(av[++i]);
		ft_lstadd_back(&a, ft_lstnew(content));
	}
	radix_sort_ps(&a, &b, &count, ft_lstsize(a));
	ft_lstiter(a, &put);
	return (0);
}
