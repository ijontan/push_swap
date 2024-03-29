/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:16:58 by itan              #+#    #+#             */
/*   Updated: 2022/11/23 00:19:20 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	power(int num, int power)
{
	int	dst;

	if (!num)
		return (0);
	if (!power)
		return (1);
	dst = num;
	while (--power > 0)
		dst *= num;
	return (dst);
}
