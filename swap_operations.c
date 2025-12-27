/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:06:18 by danborys          #+#    #+#             */
/*   Updated: 2025/12/27 17:29:42 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size >= 2)
	{
		temp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = temp;
	}
}

void	sa(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

