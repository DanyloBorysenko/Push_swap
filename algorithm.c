/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:52:49 by danborys          #+#    #+#             */
/*   Updated: 2026/01/03 14:01:08 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack *stack, int min, int ind_min)
{
	int	midl_ind;

	midl_ind = stack->size / 2;
	if (ind_min < midl_ind)
	{
		while (stack->arr[0] != min)
			ra(stack);
	}
	else
	{
		while (stack->arr[0] != min)
		{
			rra(stack);
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
	rotate_to_top(stack, min, ind_min);
}

static void	sort_3(t_stack *a)
{
	int	max;
	int	i;

	if (a->size == 2 && a->arr[0] > a->arr[1])
	{
		sa(a);
		return ;
	}
	max = a->arr[0];
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] > max)
			max = a->arr[i];
		i++;
	}
	if (max == a->arr[0])
		ra(a);
	else if (max == a->arr[1])
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
		sort_5(a, b);
}
