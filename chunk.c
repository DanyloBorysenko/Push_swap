/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:49:15 by danborys          #+#    #+#             */
/*   Updated: 2026/01/05 20:31:04 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_to_top(t_stack *stack, int el_ind)
{
	int	midl_ind;
	int	rot_count;

	rot_count = moves_ned(stack, el_ind);
	midl_ind = stack->size / 2;
	if (el_ind < midl_ind)
	{
		while (rot_count > 0)
		{
			rb(stack);
			rot_count--;
		}
	}
	else
	{
		while (rot_count > 0)
		{
			rrb(stack);
			rot_count--;
		}
	}
}

void	sort_a(int chunk_size, t_stack *a, t_stack *b)
{
	int	nums_pushed;
	int	chunk_max;

	nums_pushed = 0;
	chunk_max = chunk_size;
	while (a->size > 0)
	{
		if (a->arr[0] < chunk_max)
		{
			pb(a, b);
			if (b->arr[0] < chunk_max - chunk_size / 2)
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
}

static void	push_ind_to_a(t_stack *a, t_stack *b, int ind)
{
	rotate_b_to_top(b, ind);
	pa(b, a);
}

static void	sort_b(t_stack *a, t_stack *b)
{
	int	max_ind;
	int	prev_max_ind;

	while (b->size > 1)
	{
		max_ind = find_ind_max(b);
		prev_max_ind = find_ind_prev_max(b, max_ind);
		if (moves_ned(b, max_ind) <= moves_ned(b, prev_max_ind))
			push_ind_to_a(a, b, max_ind);
		else
		{
			push_ind_to_a(a, b, prev_max_ind);
			max_ind = find_ind_max(b);
			push_ind_to_a(a, b, max_ind);
			sa(a);
		}
	}
	if (b->size == 1)
		pa(b, a);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 65;
	sort_a(chunk_size, a, b);
	sort_b(a, b);
}
