/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:33:36 by danborys          #+#    #+#             */
/*   Updated: 2025/12/26 15:26:03 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	free_all(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	update_argc_argv(int *argc, char ***argv, int *is_allocated)
{
	int	i;

	i = 0;
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		i = 0;
		while ((*argv)[i])
			i++;
		*argc = i;
		*is_allocated = 1;
	}
	else
	{
		*argc = *argc - 1;
		*argv = *(argv) + 1;
	}
}

void	hand_err(int is_allocated, char **argv)
{
	write(2, "Error\n", 6);
	if (is_allocated == 1)
		free_all(argv);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*numbers;
	int	is_valide;
	int	is_allocated;
	t_stack *stack_a;

	is_allocated = 0;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	update_argc_argv(&argc, &argv, &is_allocated);
	is_valide = validate(argc, argv);
	if (is_valide == -1)
		hand_err(is_allocated, argv);
	numbers = parse(argc, argv);
	if (numbers == NULL)
		hand_err(is_allocated, argv);
	if (is_allocated == 1)
		free_all(argv);
	stack_a = create_stack(numbers, argc);
	free(numbers);
	free(stack_a);
}
