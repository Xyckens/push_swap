/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:32:17 by fvieira           #+#    #+#             */
/*   Updated: 2023/01/02 18:13:43 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack *stack)
{
	int	count;

	count = 0;
	while (count < stack->len - 1)
	{
		stack->stack[count] = stack->stack[count + 1];
		stack->finalpos[count] = stack->finalpos[count + 1];
		count++;
	}
}

void	push_x_to_y(t_stack *stack_x, t_stack *stack_y)
{
	int	count;

	count = 0;
	while (count < stack_y->len)
	{
		stack_y->stack[count + 1] = stack_y->stack[count];
		stack_y->finalpos[count + 1] = stack_y->finalpos[count];
		count++;
	}
	stack_y->stack[0] = stack_x->stack[0];
	stack_y->finalpos[0] = stack_x->finalpos[0];
	pop(&stack_x);
}

void	push(t_stack *stack_x, t_stack *stack_y, char c)
{
	push_x_to_y(&stack_x, &stack_y);
	stack_x->len--;
	stack_y->len++;
	ft_printf("p%c\n", c);
}
