/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:21:43 by danborys          #+#    #+#             */
/*   Updated: 2026/01/06 18:23:11 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->size > 0)
	{
		stack_to->size++;
		shift_down(stack_to);
		stack_to->arr[0] = stack_from->arr[0];
		shift_up(stack_from);
		stack_from->size--;
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
