/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:04:04 by danborys          #+#    #+#             */
/*   Updated: 2025/12/29 20:46:47 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	int_max;
	int	bits_count;

	int_max = stack->size - 1;
	bits_count = 0;
	while (int_max != 0)
	{
		int_max = int_max >> 1;
		bits_count++;
	}
	return (bits_count);
}

void	redix(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	max_bits = get_max_bits(a);
	size = a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->arr[0] >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size != 0)
			pa(b, a);
		i++;
	}
}
