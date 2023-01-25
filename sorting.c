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

int	find_right_place1(t_stack *stack, int fin)
{
	int	low;
	int	high;
	int	count;

	count = -1;
	low = -1;
	high = -1;
	while (++count < stack->len)
	{
		if (stack->finalpos[count] > fin)
			if (high == -1 || stack->finalpos[count] < stack->finalpos[high])
				high = count;
		if (stack->finalpos[count] < fin)
			if (low == -1 || stack->finalpos[count] > stack->finalpos[low])
				low = count;
	}
	if (high == -1)
		high++;
	if ((low == -1
			|| (stack->finalpos[high] - fin <= fin - stack->finalpos[low]))
		&& high != -1)
		count = high;
	else
		count = low + 1;
	return (count);
}

void	put_right_place(t_stack *stack, int finalpos, char c, char *to_a_to_b)
{
	int	count;

	if (ft_strncmp(to_a_to_b, "to_a", 4) == 0)
		count = find_right_place1(stack, finalpos);
	else
		count = find_right_place2(stack, finalpos);
	if (count > stack->len)
		count = 0;
	if (count * 2 >= stack->len)
	{
		count++;
		while (count != stack->len + 1)
		{
			do_rot(stack, c);
			count++;
		}
	}
	else
	{
		while (count > 0)
		{
			do_revrot(stack, c);
			count--;
		}
	}
}

void	putbackfromb(t_stack *stack_a, t_stack *stack_b, int limit)
{
	int	count;

	count = 0;
	while (count++ < limit)
	{
		put_right_place(stack_a, stack_b->finalpos[0], 'a', "to_a");
		push(stack_b, stack_a, 'a');
		if (stack_a->finalpos[0] == stack_a->finalpos[1] + 1)
			do_swap(stack_a, 'a');
	}
}
