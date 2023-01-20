/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:42:41 by fvieira           #+#    #+#             */
/*   Updated: 2023/01/16 16:44:20 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_right_place2(t_stack *s, int fin)
{
	int	low;
	int	high;
	int	count;

	count = 0;
	low = -1;
	high = -1;
	while (count < s->len)
	{
		if (s->finalpos[count] > fin)
			if (high == -1 || s->finalpos[count] < s->finalpos[high])
				high = count;
		if (s->finalpos[count] < fin)
			if (low == -1 || s->finalpos[count] > s->finalpos[low])
				low = count;
		count++;
	}
	if (high == -1)
		high++;
	if (low == -1
		|| (s->finalpos[high] - fin < fin - s->finalpos[low]) && high != -1)
		count = high + 1;
	else
		count = low;
	return (count);
}

void	biggestfirstplace(t_stack *stack)
{
	int	count;
	int	temp;

	count = 0;
	temp = 0;
	while (count < stack->len)
	{
		if (stack->finalpos[count] > stack->finalpos[temp])
			temp = count;
		count++;
	}
	count = temp;
	if (count * 2 >= stack->len)
	{
		count++;
		while (count++ != stack->len + 1)
			do_rot(stack, 'b');
	}
	else
	{
		while (count-- > 0)
			do_revrot(stack, 'b');
	}
}

void	sort500less(t_stack *stack_a, t_stack *stack_b, int fixed)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;

	max_bits = 0;
	num = stack_a->len - 1;
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while ((isordered(stack_a) == 1) && (++j < fixed))
		{
			num = stack_a->finalpos[0];
			if (((num >> i) & 0b00000001) == 1)
				do_revrot(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (stack_b->len > 0)
			push(stack_b, stack_a, 'a');
	}
}
