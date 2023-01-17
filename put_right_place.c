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

int	find_right_place1(t_stack *stack, int finalpos)
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
	//ft_printf("\ntcount = %d stacklen = %d\n", count, stack->len);
	//ft_printf("\ntemphigher = %d\n", high);
	//ft_printf("templower = %d\n", low);
	if ((low == -1
		|| (stack->finalpos[high] - finalpos < finalpos - stack->finalpos[low])) && high != -1)
	{
		//ft_printf("high\n");
		count = high;
	}
	else
	{
		//ft_printf("low\n");
		count = low + 1;
	}
	//ft_printf("\n stack->finalpos = %d count = %d\n", stack->finalpos[count], count);
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
		//if (stack_b->stack[0] > stack_a->stack[0])
		//{
		//}
		//printstacks(stack_a, stack_b);
		put_right_place(stack_a, stack_b->finalpos[0], 'a', "to_a");
		push(stack_b, stack_a, 'a');
		if (stack_a->finalpos[0] == stack_a->finalpos[1] + 1)
			do_swap(stack_a, 'a');
	}
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
	//printstacks(stack_a, stack_b);
	putbackfromb(stack_a, stack_b, fixed_half_len);
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
	//printstacks(stack_a, stack_b);
	putbackfromb(stack_a, stack_b, fixed_half_len);
}
