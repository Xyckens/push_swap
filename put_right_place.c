/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_right_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:36:53 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/28 21:36:54 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//deve estar alta merda
/*void	put_right_place(t_stack *stack_a, t_stack *stack_b, char c)
{
	int	index_pos;

	index_pos = stack_a->len;
	while (index_pos-- > 0)
	{
		if (stack_b->stack[stack_b->len] == stack_a->stack[index_pos])
			break ;
	}
	if (should_i_rr_or_r(&stack_a->stack, index_pos) == 1)
	{
		while (index_pos++ < stack_a->len)
			rotate(&stack_a->stack, 'a');
	}
	else
	{
		while (index_pos-- > 0)
			revrotate(&stack_a->stack, 'a');
	}
	push_x_to_y(&stack_b, &stack_a, 'a');
}*/

void sort100less(t_stack *stack_a, t_stack *stack_b)
{
	int	nbr2send;
	int	count;

	count = stack_a->len / 2;
	while (count >= 0)
	{
		push(&stack_a, &stack_b, 'b');
	}
}