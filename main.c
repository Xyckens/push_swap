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

void printstacks(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	
	count = 0;
	ft_printf("\n stack_a\n");
	while (count < stack_a->len)
	{
		ft_printf("[%d]  [%d]\n", stack_a->stack[count], stack_a->finalpos[count]);
		count++;
	}
	count = 0;
	ft_printf("\n stack_b\n");
	while (count < stack_b->len)
	{
		ft_printf("[%d]  [%d]\n", stack_b->stack[count], stack_b->finalpos[count]);
		count++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;

	stack_a.stack = malloc((argc - 1) * sizeof(int));
	stack_a.len = argc - 1;
	stack_b.len = 0;
	count = 0;
	while (count < stack_a.len)
	{
		stack_a.stack[count] = ft_atoi(argv[count + 1]);
		count++;
	}
	if (checker(&stack_a) != 1)
	{
		stack_a.finalpos = malloc((stack_a.len) * sizeof(int));
		stack_b.stack = malloc((stack_a.len) * sizeof(int));
		stack_b.finalpos = malloc((stack_a.len) * sizeof(int));
		
		finalpos(&stack_a);
	}
	//test
	//printstacks(&stack_a, &stack_b);
	if (stack_a.len < 11)
		sort10less(&stack_a, &stack_b);
	else if (stack_a.len < 101)
		sort100less(&stack_a, &stack_b);
	else
		sort500less(&stack_a, &stack_b);
	zerofirstplace(&stack_a);
	printstacks(&stack_a, &stack_b);
	//end test
	freeall(&stack_a, &stack_b);
	return (0);
}
