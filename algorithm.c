/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:52:49 by danborys          #+#    #+#             */
/*   Updated: 2025/12/27 17:51:35 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *a)
{
	int	i;
	
	i = 0;
	while (i < a->size)
	{
		printf("%d, ", a->arr[i]);
		i++;
	}	
}

static void sort_3(t_stack *a)
{
	int max;
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
	else
		rra(a);
	if (a->arr[0] > a->arr[1])
		sa(a);
}

static void	sort_4(t_stack *a, t_stack *b)
{
	pb(a, b);
	sort_3(a);
	pa(b, a);
	if (a->arr[0] > a->arr[3])
		ra(a);
	else if (a->arr[0] > a->arr[1])
		sa(a);
}

static void sort_5(t_stack *a, t_stack *b)
{
	int i;
	
	i = 0;
	pb(a, b);
	sort_4(a, b);
	pa(b, a);
	if (a->arr[0] > a->arr[4])
		ra(a);
	while (a->arr[i] < a->arr[i + 1])
	{
		sa(a);
		i++;
	}
}

void run_algorithm(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return ;
	else if (a->size <= 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	// else
	// 	chunck_sort(a, b);
	b->size++;
}

