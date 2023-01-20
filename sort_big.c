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
	if ((s->finalpos[high] - fin < fin - s->finalpos[low]
			|| low == -1) && high != -1)
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
			do_rot(stack, 'a');
	}
	else
	{
		while (count-- > 0)
			do_revrot(stack, 'a');
	}
}

/*void	sort500less(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	char	*heavy;
	int		fixedlen;
	int		fixedrest;

	fixedlen = stack_a->len / 4;
	fixedrest = stack_a->len % 4;
	heavy = bottom_top_heavy(stack_a, 1);
	count = fixedlen;
	while (count-- > 0 - fixedrest)
	{
		while (stack_a->finalpos[0] < fixedlen * 3)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	biggestfirstplace(stack_b);
	putbackfromb(stack_a, stack_b, fixedlen + fixedrest);
	heavy = bottom_top_heavy(stack_a, 1);
	while (++count < fixedlen - fixedrest)
	{
		while (stack_a->finalpos[0] < fixedlen * 2 || stack_a->finalpos[0] >= fixedlen * 3)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	biggestfirstplace(stack_b);
	putbackfromb(stack_a, stack_b, fixedlen);
	heavy = bottom_top_heavy(stack_a, -1);
	count = fixedlen;
	while (count-- > 0)
	{
		while (stack_a->finalpos[0] < fixedlen || stack_a->finalpos[0] >= fixedlen * 2)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	biggestfirstplace(stack_b);
	putbackfromb(stack_a, stack_b, fixedlen);
	heavy = bottom_top_heavy(stack_a, -1);
	while (++count < fixedlen + 1)
	{
		while (stack_a->finalpos[0] > fixedlen)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	biggestfirstplace(stack_b);
	putbackfromb(stack_a, stack_b, fixedlen + 1);
}*/

void	sort500less(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;
	int	fixed;

	max_bits = 0;
	num = stack_a->len - 1;
	fixed = stack_a->len;
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
