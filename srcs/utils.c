/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:11:46 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/15 22:09:44 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
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
