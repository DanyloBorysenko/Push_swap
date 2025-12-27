/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:46:42 by danborys          #+#    #+#             */
/*   Updated: 2025/12/27 17:26:53 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->arr);
	free(stack);
}

void	push_swap(int count, int *nums)
{
	t_stack *a;
	t_stack *b;
	int	i;
	
	a = create_stack(count);
	i = 0;
	while (i < count)
	{
		a->arr[i] = nums[i];
		i++;
	}
	a->size = count;
	b = create_stack(count);
	run_algorithm(a, b);
	i = 0;
	while (i < count)
	{
		printf("%d, ", b->arr[i]);
		i++;
	}
	free_stack(a);
	free_stack(b);
}
