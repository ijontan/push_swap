/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:57 by itan              #+#    #+#             */
/*   Updated: 2022/11/10 21:52:47 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char const **av)
{
	int	*a;
	int	*b;
	int	i;

	i = 0;
	a = malloc((ac - 1) * sizeof(int));
	if (!a)
		return (1);
	b = malloc((ac - 1) * sizeof(int));
	if (!b)
		return (1);
	while (++i < ac)
		a[i - 1] = ft_atoi(av[i]);
	i = 0;
	quick_sort(a, 0, ac - 1);
	while (i < ac - 1)
		ft_printf("%i\n", a[i++]);
	return (0);
}
