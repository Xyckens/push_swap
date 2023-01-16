/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:49:55 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/19 18:49:17 by fvieira          ###   ########.fr       */
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
