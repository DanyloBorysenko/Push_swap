/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:35:48 by danborys          #+#    #+#             */
/*   Updated: 2025/12/26 17:02:58 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->arr[stack->size - 1];
		shift_down(stack);
		stack->arr[0] = temp;
	}
}

void	rra(t_stack *stack)
{
	r_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	r_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	write(1, "rrr\n", 4);
}