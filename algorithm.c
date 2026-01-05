/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:52:49 by danborys          #+#    #+#             */
/*   Updated: 2026/01/05 19:39:45 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_to_top(t_stack *stack, int el_ind)
{
	int	midl_ind;
	int	rot_count;

	midl_ind = stack->size / 2;
	if (el_ind < midl_ind)
	{
		rot_count = el_ind;
		while (rot_count > 0)
		{
			ra(stack);
			rot_count--;
		}
	}
	else
	{
		rot_count = stack->size - el_ind;
		while (rot_count > 0)
		{
			rra(stack);
			rot_count--;
		}
	}
}

static void	move_min(t_stack *stack)
{
	int	i;
	int	min;
	int	ind_min;

	i = 1;
	min = stack->arr[0];
	ind_min = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			ind_min = i;
		}
		i++;
	}
	rotate_a_to_top(stack, ind_min);
}

static void	sort_3(t_stack *a)
{
	int	max_ind;

	if (a->size == 2 && a->arr[0] > a->arr[1])
	{
		sa(a);
		return ;
	}
	max_ind = find_ind_max(a);
	if (max_ind == 0)
		ra(a);
	else if (max_ind == 1)
		rra(a);
	if (a->arr[0] > a->arr[1])
		sa(a);
}

static void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size != 3)
	{
		move_min(a);
		pb(a, b);
	}
	sort_3(a);
	while (b->size != 0)
		pa(b, a);
}

void	run_algorithm(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return ;
	else if (a->size <= 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		chunk_sort(a, b);
}
