/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:46:42 by danborys          #+#    #+#             */
/*   Updated: 2025/12/28 17:50:50 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->arr);
	free(stack);
}

int	*intdup(int count, int *nums)
{
	int	*dup;
	int	i;

	dup = malloc(sizeof(int) * count);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < count)
	{
		dup[i] = nums[i];
		i++;
	}
	return (dup);
}

void	sort_arr(int count, int *nums)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[j] < nums[i])
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	make_indexed_arr(int count, int *nums)
{
	int	*sorted_arr;
	int	i;
	int	j;

	sorted_arr = intdup(count, nums);
	if (!sorted_arr)
		return ;
	sort_arr(count, sorted_arr);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count && nums[i] != sorted_arr[j])
			j++;
		nums[i] = j;
		i++;
	}
	free(sorted_arr);
}

void	push_swap(int count, int *nums)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	make_indexed_arr(count, nums);
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
	free_stack(a);
	free_stack(b);
}
