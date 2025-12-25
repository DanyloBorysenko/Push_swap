/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:33:36 by danborys          #+#    #+#             */
/*   Updated: 2025/12/22 19:56:18 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void free_all(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}


int	main(int argc, char **argv)
{
	int	i;
	int	*numbers;
	int	is_valide;
	int	is_allocated;

	is_allocated = 0;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		while (argv[i])
			i++;
		argc = i;
		is_allocated = 1;
	}
	else
	{
		argc = argc - 1;
		argv = argv + 1;
	}
	is_valide = validate(argc, argv);
	if (is_valide == -1)
	{
		write(2, "Error\n", 6);
		if (is_allocated == 1)
		{
			free_all(argv);
			free(argv);
		}
		exit(EXIT_FAILURE);
	}
	numbers = parse(argc, argv);
	if (numbers == NULL)
	{
		if (is_allocated == 1)
		{
			free_all(argv);
			free(argv);
		}
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (is_allocated == 1)
	{
		free_all(argv);
		free(argv);
	}
	i = 0;
	while (i < argc)
	{
		printf("%d, ", numbers[i]);
		i++;
	}
	free(numbers);
	numbers = NULL;
}
