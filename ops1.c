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

int	should_i_rr_or_r(int stack_len, int index)
{
	//esta na parte de cima do stack e para ir para o topo devo fazer ra
	if (index * 2 >= stack_len)
		return (1);
	else
		return (-1);
}

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
		count++;
	}
	stack_y->stack[0] = stack_x->stack[0];
	pop(&stack_x);
}

void	push(t_stack *stack_x, t_stack *stack_y, char c)
{
	push_x_to_y(&stack_x, &stack_y);
	ft_printf("p%c\n", c);
}
