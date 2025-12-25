/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:29:09 by danborys          #+#    #+#             */
/*   Updated: 2025/12/22 21:05:00 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static long	get_int(char *str)
{
	int		i;
	long	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res = res * sign;
	return (res);
}

int fill_arr(int count, char **argv, int *nums)
{
	int		i;
	long	integer;

	i = 0;
	while (i < count)
	{
		integer = get_int(argv[i]);
		if (integer > INT_MAX || integer < INT_MIN)
			return (0);
		nums[i] = (int) integer;
		i++;
	}
	return (1);
}

static int	check_dup(int count, int *nums)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse(int count, char **argv)
{
	int	*nums;
	int is_arr_full;

	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (NULL);
	is_arr_full = fill_arr(count, argv, nums);
	if (is_arr_full == 0)
	{
		free(nums);
		return (NULL);
	}
	if (check_dup(count, nums) == 1)
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}
