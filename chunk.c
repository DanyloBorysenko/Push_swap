/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:49:15 by danborys          #+#    #+#             */
/*   Updated: 2026/01/03 20:57:13 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_ind_max(t_stack *stack)
{
	int	i;
	int ind_of_max;

	ind_of_max = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i] > stack->arr[ind_of_max])
			ind_of_max = i;
		i++;
	}
	return (ind_of_max);
}

static void	rotate_b_to_top(t_stack *stack, int el_ind)
{
	int	midl_ind;
	int	rot_count;

	midl_ind = stack->size / 2;
	if (el_ind < midl_ind)
	{
		rot_count = el_ind;
		while (rot_count > 0)
		{
			rb(stack);
			rot_count--;
		}
	}
	else
	{
		rot_count = stack->size - el_ind;
		while (rot_count > 0)
		{
			rrb(stack);
			rot_count--;
		}
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	nums_pushed;
	int	chunk_max;
	int	ind_of_max;

	if (a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	nums_pushed = 0;
	chunk_max = chunk_size;
	while (a->size > 0)
	{
		if (a->arr[0] < chunk_max)
		{
			pb(a,b);
			if (b->arr[0] >= chunk_max - chunk_size / 2)
				rb(b);
			nums_pushed++;
			if (nums_pushed == chunk_size)
			{
				chunk_max += chunk_size;
				nums_pushed = 0;
			}
		}
		else
			ra(a);
	}
	while (b->size > 0)
	{
		ind_of_max = find_ind_max(b);
		rotate_b_to_top(b, ind_of_max);
		pa(b, a);
	}
}
