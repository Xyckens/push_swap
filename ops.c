/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:32:17 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/16 14:45:31 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*swap(int *stack, int len)
{
	int	temp;

	if (len > 1)
	{
		temp = stack[len];
		stack[len] = stack[len - 1];
		stack[len] = temp;
	}
	return (stack);
}

int	*rotate(int *stack, int len)
{
	int	temp;

	temp = stack[len - 1];
	while (len > 1)
	{
		stack[len - 1] = stack[len - 2];
		len--;
	}
	stack[0] = temp;
	return (stack);
}

int	*revrotate(int *stack, int len)
{
	int	temp;
	int	count;

	count = 0;
	temp = stack[0];
	while (count < len)
	{
		stack[count - 1] = stack[count - 2];
		count++;
	}
	stack[len] = temp;
	return (stack);
}

int	*pop(int *stack, int len)
{
	int	*stack;
	int	count;

	count = 0;
	stack = malloc((len - 1) * sizeof(int));
	while (count < len - 1)
	{
		stack[count] = stack[count];
		count++;
	}
	//barra zero aqui?
	free(stack);
	return (stack);
}

int	*push_1_to_2(int *stack_1, int *stack_2, int len1, int len2)
{
	int	*stack_1_f;
	int	count;

	count = 0;
	stack_1_f = malloc(len1 * sizeof(int));
	while (count < len1 - 1)
	{
		stack_1_f[count] = stack_1[count];
		count++;
	}
	stack_1_f[count] = stack_2[len2];
	//barra zero aqui?
	free(stack_1);
	return (stack_1_f);
}
