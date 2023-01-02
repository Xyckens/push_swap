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

int	checker(t_stack *stack)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->stack[i] == stack->stack[j]
				|| stack->stack[i] > INT_MAX || stack->stack[i] < INT_MIN)
			{
				flag = 1;
				ft_printf("Error\n");
				break ;
			}
			j++;
		}
		i++;
	}
	return (flag);
}

void finalpos(t_stack *stack)
{
	int	count1;
	int	count2;
	int lower;

	count1 = 0;
	while (count1++ <= stack->len)
	{
		lower = 0;
		count2 = 0;
		while (count2++ <= stack->len)
		{
			if (stack->stack[count2] < stack->stack[count1])
				lower++;
		}
		stack->finalpos[count1] = lower;
	}
}
