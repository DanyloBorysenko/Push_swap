/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:35:48 by danborys          #+#    #+#             */
/*   Updated: 2025/12/28 12:52:35 by danborys         ###   ########.fr       */
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
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	r_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_printf("rrr\n");
}