/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:33:36 by danborys          #+#    #+#             */
/*   Updated: 2025/12/19 19:30:37 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	is_valide;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	is_valide = validate(argc, argv);
	if (is_valide == 0)
		write(2, "Error\n", 6);
	if (argc == 2)
		exit(EXIT_SUCCESS);
}