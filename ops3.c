/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:56:35 by fvieira           #+#    #+#             */
/*   Updated: 2023/01/02 18:13:59 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rot(t_stack *stack, char c)
{
	rotate(stack);
	ft_printf("r%c\n", c);
}

void	do_bothrot(t_stack *stack_x, t_stack *stack_y)
{
	rotate(stack_x);
	rotate(stack_y);
	ft_printf("rr\n");
}

void	do_revrot(t_stack *stack, char c)
{
	revrotate(stack);
	ft_printf("rr%c\n", c);
}

void	do_bothrevrot(t_stack *stack_x, t_stack *stack_y)
{
	revrotate(stack_x);
	revrotate(stack_y);
	ft_printf("rrr\n");
}

void rot_or_revrot(t_stack *stack, char *heavy, char c)
{
	if (!ft_strncmp(heavy, "rot", 3))
		do_rot(stack, c);
	else if (!ft_strncmp(heavy, "revrot", 6))
		do_revrot(stack, c);
	else
	{
		ft_printf("something (didnt) happened");
		exit(0);
	}
}