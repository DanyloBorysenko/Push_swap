/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:32:19 by danborys          #+#    #+#             */
/*   Updated: 2025/12/26 15:12:16 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(int *ints, int size)
{
	t_stack *stack;
	
	if (!ints)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = ints;
	stack->size = size;
	return (stack);
}

void	shift_up(t_stack *stack)
{
	int	i;

	if (stack->size > 1)
	{
		i = 0;
		while (i < stack->size - 1)
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
	}
}

void	shift_down(t_stack *stack)
{
	int	i;

	if (stack->size > 1)
	{
		i = stack->size - 1;
		while (i >= 1)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
	}
}

