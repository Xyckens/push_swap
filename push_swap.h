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

int		checker(t_stack *stack);
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
void 	rot_or_revrot(t_stack *stack, char *heavy, char c);
char	*bottom_top_heavy(t_stack *stack, int flag);
void	prepare_stack_b(t_stack *stack_b, int toarrive);
void	put_right_place(t_stack *stack, int finalpos, char c);
void	putbackfromb(t_stack *stack_a, t_stack *stack_b, int limit);
void	sort100less(t_stack *stack_a, t_stack *stack_b);
void	sort500lessormore(t_stack *stack_a, t_stack *stack_b);
void	two_sort(t_stack *stack);
void	three_sort(t_stack *s);
void	printstacks(t_stack *stack_a, t_stack *stack_b);

#endif
