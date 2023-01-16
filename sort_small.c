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
