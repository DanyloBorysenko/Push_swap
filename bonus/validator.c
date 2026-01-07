/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:50:57 by danborys          #+#    #+#             */
/*   Updated: 2026/01/06 17:50:10 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	validate(int count, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (-1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
