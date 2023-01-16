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

void	sort500les(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	char	*heavy;
	int		fixedlen;

	fixedlen = stack_a->len;
	heavy = bottom_top_heavy(stack_a, 1);
	count = fixedlen / 4;
	while (count-- > 0)
	{
		while (stack_a->finalpos[0] >= fixedlen / 4)
			rot_or_revrot(stack_a, heavy, 'a');
		push(stack_a, stack_b, 'b');
	}
	while (count++ < fixedlen / 4)
	{
		while (stack_a->finalpos[0] >= fixedlen / 4)
			rot_or_revrot(stack_a, heavy, 'a');
		push(stack_a, stack_b, 'b');
	}
	count = fixedlen / 4;
	while (count-- > 0)
	{
		while (stack_a->finalpos[0] >= fixedlen / 4)
			rot_or_revrot(stack_a, heavy, 'a');
		push(stack_a, stack_b, 'b');
	}
	while (count++ < fixedlen / 4 + fixedlen % 4)
	{
		while (stack_a->finalpos[0] >= fixedlen / 4)
			rot_or_revrot(stack_a, heavy, 'a');
		push(stack_a, stack_b, 'b');
	}
	putbackfromb(stack_a, stack_b, fixedlen / 4);
}
