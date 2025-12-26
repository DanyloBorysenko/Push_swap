/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:53:51 by danborys          #+#    #+#             */
/*   Updated: 2025/12/26 15:15:50 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int	size;
	int	*arr;
}		t_stack;

int	*parse(int count, char **argv);
int	validate(int count, char **argv);
void	shift_up(t_stack *stack);
void	shift_down(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);
t_stack	*create_stack(int *ints, int size);


#endif