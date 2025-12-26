/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:19:49 by danborys          #+#    #+#             */
/*   Updated: 2025/12/26 17:00:23 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->size > 0)
	{
		shift_down(stack_to);
		stack_to->arr[0] = stack_from->arr[0];
		stack_to->size++;
		shift_up(stack_from);
		stack_from->size--;
	}
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);	
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);	
}

