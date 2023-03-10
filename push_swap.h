/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:55:53 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/15 15:07:37 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack {
	int	*stack;
	int	*finalpos;
	int	len;
}	t_stack;

void	checker(t_stack *stack);
void	finalpos(t_stack *stack);
void	push(t_stack *stack_x, t_stack *stack_y, char c);
void	rotate(t_stack *stack);
void	revrotate(t_stack *stack);
void	do_swap(t_stack *stack, char c);
void	do_bothswap(t_stack *stack_x, t_stack *stack_y);
void	do_rot(t_stack *stack, char c);
void	do_bothrot(t_stack *stack_x, t_stack *stack_y);
void	do_revrot(t_stack *stack, char c);
void	do_bothrevrot(t_stack *stack_x, t_stack *stack_y);
void	rot_or_revrot(t_stack *stack, char *heavy, char c);
char	*bottom_top_heavy(t_stack *stack, int flag);
void	prepare_stack_b(t_stack *stack_b, int toarrive);
void	put_right_place(t_stack *stack, int finalpos, char c, char *to_a_to_b);
void	putbackfromb(t_stack *stack_a, t_stack *stack_b, int limit);
void	sort100less(t_stack *stack_a, t_stack *stack_b);
void	two_sort(t_stack *stack);
void	three_sort(t_stack *s);
void	printstacks(t_stack *stack_a, t_stack *stack_b);
int		findsecondbiggest(t_stack *stack, int finalpos);
void	zerofirstplace(t_stack *stack);
void	sort10less(t_stack *stack_a, t_stack *stack_b);
int		find_right_place1(t_stack *stack, int finalpos);
int		find_right_place2(t_stack *stack, int finalpos);
void	sort500less(t_stack *stack_a, t_stack *stack_b, int fixed);
void	biggestfirstplace(t_stack *stack);
int		isordered(t_stack *stack);

static inline int	is_digit_or_signal(char c)
{
	if ((c >= '0' && c <= '9') || (c == '-' || c == '+') || c == ' ')
		return (1);
	return (0);
}

#endif
