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

void	two_sort(t_stack **stack)
{
	if ((*stack)->stack[0] < (*stack)->stack[1])
		do_swap(stack, 'a');
}

void	three_sort(t_stack **s)
{
	if ((*s)->stack[0] > (*s)->stack[1] && (*s)->stack[1] < (*s)->stack[2]
		&& (*s)->stack[0] < (*s)->stack[2])
		do_swap(s, 'a');
	else if ((*s)->stack[0] > (*s)->stack[1] && (*s)->stack[1] > (*s)->stack[2]
		&& (*s)->stack[0] > (*s)->stack[2])
	{
		do_swap(s, 'a');
		do_revrot(s, 'a');
	}
	else if ((*s)->stack[0] > (*s)->stack[1] && (*s)->stack[1] < (*s)->stack[2]
		&& (*s)->stack[0] > (*s)->stack[2])
		do_rot(s, 'a');
	else if ((*s)->stack[0] < (*s)->stack[1] && (*s)->stack[1] > (*s)->stack[2]
		&& (*s)->stack[0] < (*s)->stack[2])
	{
		do_swap(s, 'a');
		do_rot(s, 'a');
	}
	if ((*s)->stack[0] < (*s)->stack[1] && (*s)->stack[1] > (*s)->stack[2]
		&& (*s)->stack[0] > (*s)->stack[2])
		do_revrot(s, 'a');
}
/*
void	four_sort(t_stack *stack_a, t_stack *stack_b)
{
	push(&stack_a, &stack_b, 'b');
	three_sort(&stack_a);
	push(&stack_b, &stack_a, 'a');
	if (stack_a[i] > stack_a[i + 1] && i < 4)
	{
		
	}
}

void	five_sort(int *stack_a, int *stack_b)
{
	
}*/