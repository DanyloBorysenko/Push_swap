/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:32:19 by danborys          #+#    #+#             */
/*   Updated: 2025/12/28 17:48:24 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int nums_count)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = calloc(sizeof(int), nums_count);
	if (!stack->arr)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
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

	if (stack->size > 0)
	{
		i = stack->size;
		while (i >= 1)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
	}
}

void	print_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		ft_printf("%d, ", a->arr[i]);
		i++;
	}
	ft_printf("\n");
}
