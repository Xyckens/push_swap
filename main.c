/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:55:18 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/16 14:47:33 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freeall(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	if (!stack_b->stack && !stack_b->finalpos && !stack_a->finalpos)
	{
		free(stack_b->stack);
		free(stack_b->finalpos);
		free(stack_a->finalpos);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;

	stack_a->stack = malloc((argc - 1) * sizeof(int));
	if (checker(stack_a, argc - 1) != 1)
	{
		stack_a->finalpos = malloc((argc - 1) * sizeof(int));
		stack_b->stack = malloc((argc - 1) * sizeof(int));
		stack_b->finalpos = malloc((argc - 1) * sizeof(int));
		count = 0;
		while (count < argc - 1)
		{
			stack_a->stack[argc - 1 - count] = ft_atoi(argv[count + 1]);
			count++;
		}
		finalpos(&stack_a);
	}
	freeall(&stack_a, &stack_b);
	return (0);
}
