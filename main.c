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

	stack_a = malloc(argc * sizeof(int));
	stack_b = malloc(1 * sizeof(int));
	count = 0;
	while (count < argc - 1)
	{
		stack_a[count] = ft_atoi(argv[count + 1]);
		count++;
	}
	//barra zero aqui e o tamanho de malloc deve estar mal
	/*while (count-- > 0)
		printf(" %d ", stack_a[count]);*/
	return (0);
}
