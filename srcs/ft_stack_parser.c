/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:25:39 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/13 20:28:39 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static t_bool	ft_nums_checker(char **args)
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

t_bool	ft_fill_stack(t_stack stack, char **args)
{
	long	digit;
	int		i;

	i = 0;
	while (args[i])
	{
		
		i++;
	}
}

t_bool	ft_stack_parser(t_stack *stack, int argc, char *argv[])
{
	char	**splited_argv;
	t_bool	is_allocated;

	if (argc < 2)
		return (FALSE);
	is_allocated = FALSE;
	if (argc == 2)
	{
		splited_argv = ft_split(argv[1], ' ');
		is_allocated = TRUE;
	}
	else
		splited_argv = argv + 1;
	if (!splited_argv || !ft_nums_checker(splited_argv)
		|| !ft_fill_stack(stack, splited_argv))
	{
		if (is_allocated)
			ft_free_splited_args(splited_argv);
		return (FALSE);
	}
	return (TRUE);
}
