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

int	all_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (is_digit_or_signal(av[i][j]) == 0)
				return (0);
			j++;
		}
	}
	return (1);
}

void	freeall(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_b->stack);
	free(stack_a->finalpos);
	free(stack_b->finalpos);
}

void	printstacks(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	ft_printf("\n stack_a\n");
	if (a != NULL)
	{
		while (count < a->len)
		{
			ft_printf("[%d]  [%d]\n", a->stack[count], a->finalpos[count]);
			count++;
		}
	}
	if (b == NULL)
		return ;
	count = 0;
	ft_printf("\n stack_b\n");
	while (count < b->len)
	{
		ft_printf("[%d]  [%d]\n", b->stack[count], b->finalpos[count]);
		count++;
	}
}

int	valid(ssize_t nb, t_stack *stack)
{
	if (nb > 2147483647)
	{
		ft_printf("Error\n");
		free(stack->stack);
		exit(1);
	}
	return ((int) nb);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;

	if (all_digits(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	stack_a.stack = malloc((argc - 1) * sizeof(int));
	stack_a.len = argc - 1;
	stack_b.len = 0;
	count = -1;
	while (++count < stack_a.len)
		stack_a.stack[count] = valid(ft_atoi(argv[count + 1]), &stack_a);
	checker(&stack_a);
	stack_a.finalpos = ft_calloc((stack_a.len), sizeof(int));
	stack_b.stack = ft_calloc((stack_a.len), sizeof(int));
	stack_b.finalpos = ft_calloc((stack_a.len), sizeof(int));
	finalpos(&stack_a);
	if (stack_a.len < 11)
		sort10less(&stack_a, &stack_b);
	else if (stack_a.len < 101)
		sort100less(&stack_a, &stack_b);
	else
		sort500less(&stack_a, &stack_b, stack_a.len);
	zerofirstplace(&stack_a);
	freeall(&stack_a, &stack_b);
	return (0);
}
