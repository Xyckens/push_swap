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

//deve estar alta merda
/*void	put_right_place(t_stack *stack_a, t_stack *stack_b, char c)
{
	int	index_pos;

	index_pos = stack_a->len;
	while (index_pos-- > 0)
	{
		if (stack_b->stack[stack_b->len] == stack_a->stack[index_pos])
			break ;
	}
	if (should_i_rr_or_r(&stack_a->stack, index_pos) == 1)
	{
		while (index_pos++ < stack_a->len)
			rotate(&stack_a->stack, 'a');
	}
	else
	{
		while (index_pos-- > 0)
			revrotate(&stack_a->stack, 'a');
	}
	push_x_to_y(&stack_b, &stack_a, 'a');
}*/

char *bottom_top_heavy(t_stack *stack)
{
	int	count2;
	int	max;

	max = stack_a->len;
	count2 = 0;
	while(max--)
	{
		if (stack_a->finalpos[max] =< stack_a->len / 2)
			count2++;
		else if (stack_a->finalpos[max] > stack_a->len / 2)
			count2--;
	}
	if (count2 >= 0)
		return ("top_heavy");
	else
		return ("bottom_heavy");
}

void sort100less(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	int		count2;
	int		fixed_half_len;
	char	*heavy;

	heavy = bottom_top_heavy(&stack_a);
	count = stack_a->len / 2;
	fixed_half_len = stack_a->len / 2;
	while (count-- >= 0)
	{
		while (stack_a->finalpos[0] =< fixed_half_len)
			rot_or_revrot(&stack_a, heavy, 'a');
		//aqui devia preparar o stackb para receber perto do sitio correto o numero do stacka
		push(&stack_a, &stack_b, 'b');
	}
}