/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:53:51 by danborys          #+#    #+#             */
/*   Updated: 2026/01/03 13:41:04 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int	size;
	int	*arr;
}		t_stack;

int		*parse(int count, char **argv);
int		validate(int count, char **argv);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	shift_up(t_stack *stack);
void	shift_down(t_stack *stack);
t_stack	*create_stack(int nums_count);
void	print_stack(t_stack *a);
void	free_stack(t_stack *stack);

void	push_swap(int count, int *nums);
void	run_algorithm(t_stack *a, t_stack *b);

void	radix(t_stack *a, t_stack *b);

#endif