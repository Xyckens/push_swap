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
	while (i < stack->len && flag == 0)
	{
		j = i + 1;
		while (j < stack->len)
		{
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

void finalpos(t_stack *stack)
{
	int	count1;
	int	count2;
	int lower;

	count1 = 0;
	while (count1 < stack->len)
	{
		lower = 0;
		count2 = 0;
		while (count2 < stack->len)
		{
			if (stack->stack[count2] < stack->stack[count1])
				lower++;
			count2++;
		}
		stack->finalpos[count1] = lower;
		count1++;
	}
}

void	zerofirstplace(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack->finalpos[count] != 0)
		count++;
	if (count * 2 >= stack->len)
	{
		count++;
		while (count != stack->len + 1)
		{
			do_rot(stack, 'a');
			count++;
		}
	}
	else
	{
		while (count > 0)
		{
			do_revrot(stack, 'a');
			count--;
		}
	}
}