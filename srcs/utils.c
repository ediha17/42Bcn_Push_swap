/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:11:46 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/18 13:33:21 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
}

long	ft_atol(char *str, t_bool *err_flag)
{
	long	digit;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	digit = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (sign * digit) > INT_MIN && (sign * digit) < INT_MAX)
	{
		digit = digit * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || (sign * digit) < INT_MIN || (sign * digit) > INT_MAX)
		return ((*err_flag = TRUE), 0);
	return (sign * digit);
}

t_bool	ft_have_duplicates(long *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_bool	ft_nums_checker(char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (args[i][j] == '\0')
			return (FALSE);
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
