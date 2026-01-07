/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:15 by danborys          #+#    #+#             */
/*   Updated: 2026/01/07 18:47:56 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	exec_push_swap(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(line, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(a, b);
	else
		return (0);
	return (1);
}

int	exec_rotate(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else
		return (0);
	return (1);
}

int	exec_r_rotate(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "rra\n") == 0)
		r_rotate(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		r_rotate(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		r_rotate(a);
		r_rotate(b);
	}
	else
		return (0);
	return (1);
}

void	exec_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		res;

	line = get_next_line(0);
	while (line != NULL)
	{
		res = 0;
		res += exec_push_swap(line, a, b);
		res += exec_rotate(line, a, b);
		res += exec_r_rotate(line, a, b);
		if (res == 1)
		{
			free(line);
			line = get_next_line(0);
			continue ;
		}
		free(line);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
