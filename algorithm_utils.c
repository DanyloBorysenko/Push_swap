/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:19:19 by danborys          #+#    #+#             */
/*   Updated: 2026/01/05 20:29:26 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_ind_max(t_stack *stack)
{
	int	i;
	int	ind_of_max;

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

int	moves_ned(t_stack *stack, int el_ind)
{
	int	midl_ind;
	int	moves;

	midl_ind = stack->size / 2;
	if (el_ind < midl_ind)
		moves = el_ind;
	else
		moves = stack->size - el_ind;
	return (moves);
}

int	find_ind_prev_max(t_stack *stack, int max_ind)
{
	int	i;
	int	prev_max_ind;

	if (max_ind == 0)
		prev_max_ind = 1;
	else
		prev_max_ind = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < stack->arr[max_ind]
			&& stack->arr[i] > stack->arr[prev_max_ind])
			prev_max_ind = i;
		i++;
	}
	return (prev_max_ind);
}
