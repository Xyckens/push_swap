/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:32:17 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/19 18:40:14 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*swap(int *stack, int len)
{
	int	temp;

	if (len > 0)
	{
		temp = stack[len];
		stack[len] = stack[len - 1];
		stack[len] = temp;
	}
	return (stack);
}

int	should_i_rr_or_r(int stack_len, int index)
{
	//esta na parte de cima do stack e para ir para o topo devo fazer ra
	if (index * 2 >= stack_len)
		return (1);
	else
		return (-1);	
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

void	*revrotate(int *stack, int len)
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
	int	*stack_f;
	int	count;

	count = 0;
	stack_f = malloc((len - 1) * sizeof(int));
	while (count < len - 1)
	{
		stack_f[count] = stack[count + 1];
		count++;
	}
	free(stack);
	return (stack_f);
}

int	*push_x_to_y(int *stack_x, int *stack_y, int len1, int len2)
{
	int	*stack_y_f;
	int	count;

	count = 0;
	stack_y_f = malloc((len2 + 1) * sizeof(int));
	while (count < len2)
	{
		stack_y_f[count + 1] = stack_y[count];
		count++;
	}
	stack_y_f[0] = stack_x[0];
	free(stack_y);
	return (stack_y_f);
}
