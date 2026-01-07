/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:30:26 by danborys          #+#    #+#             */
/*   Updated: 2026/01/07 18:32:41 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int	size;
	int	*arr;
}		t_stack;

int		*parse(int count, char **argv);
int		validate(int count, char **argv);

void	push(t_stack *stack_from, t_stack *stack_to);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);
void	swap(t_stack *stack);

void	shift_up(t_stack *stack);
void	shift_down(t_stack *stack);
t_stack	*create_stack(int nums_count);
void	print_stack(t_stack *a);
void	free_stack(t_stack *stack);

void	exec_instructions(t_stack *a, t_stack *b);
int		exec_push_swap(char *line, t_stack *a, t_stack *b);
int		exec_rotate(char *line, t_stack *a, t_stack *b);
int		exec_r_rotate(char *line, t_stack *a, t_stack *b);

void	check_sorting(int count, int *nums);

#endif