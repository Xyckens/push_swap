/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:06:40 by fvieira           #+#    #+#             */
/*   Updated: 2023/01/15 19:06:41 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_stack *stack)
{
	if (stack->stack[0] < stack->stack[1])
		do_swap(stack, 'a');
}

void	three_sort(t_stack *s)
{
	if (s->stack[0] > s->stack[1] && s->stack[1] < s->stack[2]
		&& s->stack[0] < s->stack[2])
		do_swap(s, 'a');
	else if (s->stack[0] > s->stack[1] && s->stack[1] > s->stack[2]
		&& s->stack[0] > s->stack[2])
	{
		do_swap(s, 'a');
		do_rot(s, 'a');
	}
	else if (s->stack[0] > s->stack[1] && s->stack[1] < s->stack[2]
		&& s->stack[0] > s->stack[2])
		do_revrot(s, 'a');
	else if (s->stack[0] < s->stack[1] && s->stack[1] > s->stack[2]
		&& s->stack[0] < s->stack[2])
	{
		do_swap(s, 'a');
		do_revrot(s, 'a');
	}
	else if (s->stack[0] < s->stack[1] && s->stack[1] > s->stack[2]
		&& s->stack[0] > s->stack[2])
		do_rot(s, 'a');
}

void	sort10less(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	char	*heavy;
	int		fixedlen;

	fixedlen = stack_a->len - 3;
	heavy = bottom_top_heavy(stack_a, -1);
	count = fixedlen;
	if (stack_a->len == 2)
		two_sort(stack_a);
	else if (stack_a->len == 3)
		three_sort(stack_a);
	else
	{
		while (count-- > 0)
		{
			while (stack_a->finalpos[0] >= fixedlen)
				rot_or_revrot(stack_a, heavy, 'a');
			push(stack_a, stack_b, 'b');
		}
		three_sort(stack_a);
		putbackfromb(stack_a, stack_b, fixedlen);
	}
}
