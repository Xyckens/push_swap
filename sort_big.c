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

int	find_right_place2(t_stack *stack, int finalpos)
{
	int low;
	int high;
	int	count;

	count = 0;
	low = -1;
	high = -1;
	while (count < stack->len)
	{
		if (stack->finalpos[count] > finalpos)
			if (high == -1 || stack->finalpos[count] < stack->finalpos[high])
				high = count;
		if (stack->finalpos[count] < finalpos)
			if (low == -1 || stack->finalpos[count] > stack->finalpos[low])
				low = count;
		count++;
	}
	//("\ntcount = %d stacklen = %d\n", count, stack->len);
	//ft_printf("\ntemphigher = %d\n", high);
	//ft_printf("templower = %d\n", low);
	if ((low == -1
		|| (stack->finalpos[high] - finalpos < finalpos - stack->finalpos[low])) && high != -1)
	{
		//ft_printf("high\n");
		count = high + 1;
	}
	else
	{
		//ft_printf("low\n");
		count = low;
	}
	//ft_printf("\n stack->finalpos = %d count = %d\n", stack->finalpos[count], count);
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
	//ft_printf("\n stack->finalpos = %d count = %d\n", stack->finalpos[count], count);
	if (count * 2 >= stack->len)
	{
		count++;
		while (count != stack->len + 1)
		{
			do_rot(stack, 'a');
			count++;
		}
	}
	else
	{
		while (count > 0)
		{
			do_revrot(stack, 'a');
			count--;
		}
	}
}

void	sort500less(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	char	*heavy;
	int		fixedlen;

	fixedlen = stack_a->len;
	heavy = bottom_top_heavy(stack_a, 1);
	count = fixedlen / 4;
	while (count-- > 0)
	{
		while (stack_a->finalpos[0] <= fixedlen * 3 / 4)
			rot_or_revrot(stack_a, heavy, 'a');
		printstacks(stack_a, stack_b);
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	biggestfirstplace(stack_b);
	printstacks(stack_a, stack_b);
	exit(1);
	putbackfromb(stack_a, stack_b, fixedlen / 4);
	heavy = bottom_top_heavy(stack_a, 1);
	while (count++ < fixedlen / 4)
	{
		while (stack_a->finalpos[0] >= fixedlen / 2 && stack_a->finalpos[0] < fixedlen * 3 / 4)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	putbackfromb(stack_a, stack_b, fixedlen / 4);
	heavy = bottom_top_heavy(stack_a, -1);
	count = fixedlen / 4;
	while (count-- > 0)
	{
		while (stack_a->finalpos[0] <= fixedlen / 4 && stack_a->finalpos[0] < fixedlen / 2)
			rot_or_revrot(stack_a, heavy, 'a');
		put_right_place(stack_b, stack_a->finalpos[0], 'b', "to_b");
		push(stack_a, stack_b, 'b');
	}
	putbackfromb(stack_a, stack_b, fixedlen / 4 + fixedlen % 4);
	heavy = bottom_top_heavy(stack_a, -1);
	while (count++ < fixedlen / 4 + fixedlen % 4)
	{
		while (stack_a->finalpos[0] > fixedlen / 4  + fixedlen % 4)
			rot_or_revrot(stack_a, heavy, 'a');
		push(stack_a, stack_b, 'b');
	}
	putbackfromb(stack_a, stack_b, fixedlen / 4);
}
