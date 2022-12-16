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

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	count;

	stack_a = malloc((argc - 1) * sizeof(int));
	if (checker(stack_a, argc - 1) == 1)
	{
		free(stack_a);
		return (0);
	}
	stack_b = malloc(1 * sizeof(int));
	count = 0;
	while (count < argc - 1)
	{
		stack_a[argc - 1 - count] = ft_atoi(argv[count + 1]);
		count++;
	}
	/*while (count-- > 0)
		printf(" %d ", stack_a[count]);*/
	free(stack_b);
	free(stack_a);
	return (0);
}
