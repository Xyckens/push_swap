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

void	prepare_stack_b(t_stack *stack_b, int toarrive)
{
	if (stack_b->len > 1)
	{
		if (toarrive < stack_b->stack[0])
		{
			if (stack_b->stack[0] > stack_b->stack[1])
				do_swap(stack_b, 'b');
		}
	}
}

void	put_right_place(t_stack *stack, int finalpos, char c)
{
	int	count;

	count = 0;
	while (count < stack->len)
	{
		ft_printf("[%d]  [%d]\n", stack->stack[count], stack->finalpos[count]);
		count++;
	}
	count = 0;
	while (stack->finalpos[count] < finalpos && count <= stack->len)
		count++;
	ft_printf("len = %d\n",stack->len);
	ft_printf("count = %d, finalpos = %d, stack->finalpos = %d\n", count, stack->finalpos[count]);
	if (count * 2 >= stack->len)
	{
		while (count++ != stack->len + 1)
			do_revrot(stack, c);
	}
	else
	{
		while (count-- > 0)
			do_rot(stack, c);
	}
}
void	putbackfromb(t_stack *stack_a, t_stack *stack_b, int limit)
{
	int	count;

	count = 0;
	while (count++ < limit)
	{
		if (stack_b->stack[0] < stack_a->stack[0])
		{
			ft_printf("entrou\n");
			put_right_place(stack_a, stack_b->finalpos[0], 'a');
		}
		push(stack_b, stack_a, 'a');
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
		{
			rot_or_revrot(stack_a, heavy, 'a');
		}
		prepare_stack_b(stack_b, stack_a->stack[0]);
		push(stack_a, stack_b, 'b');
	}
	putbackfromb(stack_a, stack_b, fixed_half_len);
	heavy = bottom_top_heavy(stack_a, -1);
	count = stack_a->len / 2;

	while (count-- > 0)
	{
		while (stack_a->finalpos[0] > fixed_half_len)
		{
			rot_or_revrot(stack_a, heavy, 'a');
		}
		prepare_stack_b(stack_b, stack_a->stack[0]);
		push(stack_a, stack_b, 'b');
	}
	putbackfromb(stack_a, stack_b, fixed_half_len);
	/*count = 0;
	ft_printf("\n stacka\n");

	while (count < stack_a->len)
	{
		ft_printf("[%d]  [%d]\n", stack_a->stack[count], stack_a->finalpos[count]);
		count++;
	}
	count = 0;
	ft_printf("\n stackb\n");
	while (count < stack_b->len)
	{
		ft_printf("[%d]  [%d]\n", stack_b->stack[count], stack_b->finalpos[count]);
		count++;
	}*/
}

void	sort500lessormore(t_stack *stack_a, t_stack *stack_b)
{

}