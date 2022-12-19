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

void	two_sort(int *stack)
{
	if (stack[0] < stack[1])
	{
		swap(&stack, 1);
		ft_printf("sa\n");
	}
}

void	three_sort(int *stack)
{
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
	{
		stack = swap(stack, 2);
		ft_printf("sa\n");
	}
	else if (stack[0] > stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
	{
		stack = swap(stack, 2);
		ft_printf("sa\n");
		stack = revrotate(stack,2);
		ft_printf("rra\n");
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
	{
		rotate(stack, 2);
		ft_printf("ra\n");
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
	{
		stack = swap(stack, 2);
		ft_printf("sa\n");
		stack = rotate(stack,2);
		ft_printf("ra\n");
	}
	if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
	{
		stack = revrotate(stack, 2);
		ft_printf("rra\n");
	}
}

void	four_sort(int *stack_a, int *stack_b)
{
	stack_b = push_x_to_y(&stack_a, &stack_b, 4, 0);
	stack_a = pop(stack_a, 4);
	ft_printf("pb\n");
	three_sort(&stack_a);
	stack_a = push_x_to_y(&stack_b, &stack_a, 1, 3);
	stack_b = pop(stack_a, 1);
	ft_printf("pa\n");
	/*if (stack_a[i] > stack_a[i + 1] && i < 4)
	{
		
	}*/
}

void	five_sort(int *stack_a, int *stack_b)
{
	
}