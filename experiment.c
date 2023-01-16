/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experiment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:21:58 by fvieira           #+#    #+#             */
/*   Updated: 2023/01/15 16:22:01 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	findsecondbiggest(t_stack *stack, int finalpos)
{
	int low;
	int high;
	int	count;

	count = 0;
	low = -1;
	high = -1;
	while (count <= stack->len)
	{
		if (stack->finalpos[count] > finalpos)
			if (high == -1 || stack->finalpos[count] < stack->finalpos[high])
				high = count;
		if (stack->finalpos[count] < finalpos)
			if (low == -1 || stack->finalpos[count] > stack->finalpos[low])
				low = count;
		count++;
	}
	ft_printf("\ntemphigher = %d\n", high);
	ft_printf("templower = %d\n", low);
	if ((low == -1 && high >= 0)
		|| (stack->finalpos[high] - finalpos < finalpos - stack->finalpos[low]))
	{
		ft_printf("templower\n");
		count = high;
	}
	else
	{
		ft_printf("temphigher\n");
		count = low + 1;
	}
	ft_printf("\n stack->finalpos = %d count = %d\n", stack->finalpos[count], count);
	return (count);


}
void	put_right_place(t_stack *stack, int finalpos, char c)
{
	int	count;

	count = find_right_place(stack, finalpos);
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


















/*int	findsecondbiggest(t_stack *stack, int finalpos)
{
	int templower;
	int temphigher;
	int	count;

	count = 0;
	templower = -1;
	temphigher = -1;
	while (count < stack->len)
	{
		if (stack->finalpos[count] > finalpos)
			if (temphigher == -1 ||stack->finalpos[temphigher] > stack->finalpos[count])
				temphigher = count;
		if (stack->finalpos[count] < finalpos)
			if (templower == -1 || stack->finalpos[templower] < stack->finalpos[count])
				templower = count;
		count++;
	}
		ft_printf("\ntemphigher = %d\n", temphigher);
		ft_printf("templower = %d\n", templower);
	if ((temphigher == -1
		|| ((finalpos - stack->finalpos[templower]) < (stack->finalpos[temphigher] - finalpos))
		|| temphigher == templower + 1) && templower != -1)
	{
		ft_printf("templower\n");
		count = templower + 1;
		if (count <= 2)
			count++;
	}
	else
	{
		ft_printf("temphigher\n");
		count = temphigher + 1;
		if (count >= stack->len - 2)
			count--;
	}
	if (count * 2 >= stack->len)
		count++;
	else
		count--;
	ft_printf("\n stack->finalpos = %d count = %d\n", stack->finalpos[count], count);
	return (count);
}
void	put_right_place(t_stack *stack, int finalpos, char c)
{
	int	count;

	count = findsecondbiggest(stack, finalpos);
	if (count * 2 >= stack->len)
	{
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
}*/