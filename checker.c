/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:19:03 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/16 20:19:10 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(int *stack, int len)
{
	int count;
	int	count2;
	int	flag;

	count = 0;
	flag = 0;
	while (count < len)
	{
		count2 = count + 1;
		while (count2 < len)
		{
			if (stack[count] == stack[count2] || stack[count] > INT_MAX
				|| stack[count] < INT_MIN)
			{
				flag = 1;
				break ;
			}
			count2++;
		}
		count++;
	}
	return (flag);
}
