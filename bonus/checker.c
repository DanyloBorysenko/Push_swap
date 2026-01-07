/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:46:42 by danborys          #+#    #+#             */
/*   Updated: 2026/01/07 18:25:55 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	check_sorting(int count, int *nums)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = create_stack(count);
	i = 0;
	while (i < count)
	{
		a->arr[i] = nums[i];
		i++;
	}
	a->size = count;
	b = create_stack(count);
	exec_instructions(a, b);
	if (is_stack_sorted(a) == 1 && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
}
