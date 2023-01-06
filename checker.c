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
	int count;

	i = 0;
	flag = 0;
	count = 0;
	while (count < 5)
	{
		ft_printf("[%d]\n", stack->stack[count]);
		count++;
	}
	while (i < stack->len && flag == 0)
	{
		j = i + 1;
		while (j < stack->len)
		{
			ft_printf("%d %d \n", stack->stack[i], stack->stack[j]);
			if (stack->stack[i] == stack->stack[j]
				|| stack->stack[j] > INT_MAX || stack->stack[j] < INT_MIN)
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

void finalpos(t_stack **stack)
{
	int	count1;
	int	count2;
	int lower;

	count1 = 0;
	while (count1++ <= (*stack)->len)
	{
		lower = 0;
		count2 = 0;
		while (count2 <= (*stack)->len)
		{
			if ((*stack)->stack[count2] < (*stack)->stack[count1])
				lower++;
			count2++;
		}
		(*stack)->finalpos[count1] = lower;
	}
}
