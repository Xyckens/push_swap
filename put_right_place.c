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

char	*bottom_top_heavy(t_stack *stack, int flag)
{
	int	count2;
	int	max;

	max = stack->len;
	count2 = 0;
	while (max--)
	{
		if (stack->finalpos[max] <= stack->len / 2)
			count2++;
		else if (stack->finalpos[max] > stack->len / 2)
			count2--;
	}
	if (count2 >= 0 && flag == 1)
		return ("rot");
	else if (count2 <= 0 && flag == -1)
		return ("rot");
	else
		return ("revrot");
}

void	toomanylines(t_stack *stack_a, t_stack *stack_b, int fixed_half_len)
{
	int		count;
	char	*heavy;

	heavy = bottom_top_heavy(stack_a, -1);
	count = stack_a->len / 2;
	while (count-- > 0)
	{
		while (stack_a->finalpos[0] >= fixed_half_len)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	biggestfirstplace(stack_b);
	putbackfromb(stack_a, stack_b, fixed_half_len);
}

void	sort100less(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	int		fixed_half_len;
	char	*heavy;

	heavy = bottom_top_heavy(stack_a, 1);
	count = stack_a->len / 2;
	fixed_half_len = stack_a->len / 2;
	while (count-- > 0)
	{
		while (stack_a->finalpos[0] < fixed_half_len)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	biggestfirstplace(stack_b);
	putbackfromb(stack_a, stack_b, fixed_half_len);
	toomanylines(stack_a, stack_b, fixed_half_len);
}
