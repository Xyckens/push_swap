/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:29:21 by fvieira           #+#    #+#             */
/*   Updated: 2023/01/02 18:13:51 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len > 0)
	{
		temp = stack->stack[stack->len];
		stack->stack[stack->len] = stack->stack[stack->len - 1];
		stack->stack[stack->len] = temp;
	}
}

void	rotate(t_stack *stack)
{
	int	temp;
	int	temp_len;

	temp = stack->stack[stack->len - 1];
	temp_len = stack_len;
	while (temp_len > 1)
	{
		stack->stack[temp_len - 1] = stack->stack[temp_len - 2];
		temp_len--;
	}
	stack->stack[0] = temp;
}

void	revrotate(t_stack *stack)
{
	int	temp;
	int	count;

	count = 0;
	temp = stack->stack[0];
	while (count < stack->len)
	{
		stack->stack[count - 1] = stack->stack[count - 2];
		count++;
	}
	stack->stack[stack->len] = temp;
}

void	do_swap(t_stack *stack, char c)
{
	swap(&stack);
	ft_printf("s%c\n", c);
}

void	do_bothswap(t_stack *stack_x, t_stack *stack_y)
{
	swap(&stack_x);
	swap(&stack_y);
	ft_printf("ss\n");
}
