/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:27:02 by danborys          #+#    #+#             */
/*   Updated: 2025/12/26 16:27:49 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size >= 2)
	{
		temp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = temp;
	}
}

void	push(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b->size > 0)
	{
		shift_down(stack_a);
		stack_a->arr[0] = stack_b->arr[0];
		stack_a->size++;
		shift_up(stack_b);
		stack_b->size--;
	}
}

void	rotate(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->arr[0];
		shift_up(stack);
		stack->arr[stack->size - 1] = temp;
	}
}

void	r_rotate(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->arr[stack->size - 1];
		shift_down(stack);
		stack->arr[0] = temp;
	}
}
