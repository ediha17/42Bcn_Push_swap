/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_parsing_fts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:57:14 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/16 22:13:59 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

long	*ft_args_to_long(char **args, int size)
{
	long	*digits;
	t_bool	error;
	int		i;

	digits = malloc(sizeof(long) * size);
	if (!digits)
		return (NULL);
	i = 0;
	error = FALSE;
	if (!ft_nums_checker(args))
		error = TRUE;
	while (i < size && !error)
	{
		digits[i] = ft_atol(args[i], &error);
		i++;
	}
	if (error)
		return (free(digits), NULL);
	return (digits);
}

char	**ft_get_args(int argc, char *argv[], t_bool *is_splited)
{
	if (argc == 2)
	{
		*is_splited = TRUE;
		return (ft_split(argv[1], ' '));
	}
	*is_splited = FALSE;
	return (argv + 1);
}
