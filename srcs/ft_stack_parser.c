/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:25:39 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/16 15:03:14 by ehorvat          ###   ########.fr       */
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

static long	*ft_args_to_long(char **args, int size)
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

static t_bool	ft_add_to_stack(t_stack *stack, t_number *n_to_add)
{
	t_number	*last_n;

	last_n = malloc(sizeof(t_number));
	if (!last_n)
		return (FALSE);
	last_n = stack->top;
	while (last_n->next_n)
		last_n = last_n->next_n;
	last_n->next_n = n_to_add;
	return (TRUE);
}

static t_bool	ft_fill_stack(t_stack *stack, long *n_to_fill)
{
	t_number	*tmp_n;
	int			i;

	i = 0;
	while (n_to_fill[i])
	{
		tmp_n = malloc(sizeof(t_number));
		if (!tmp_n)
			return (FALSE);
		tmp_n->value = (int)n_to_fill[i];
		tmp_n->next_n = NULL;
		if (!stack->top)
			stack->top = tmp_n;
		else
			if (!ft_add_to_stack(stack, tmp_n))
				return (free(tmp_n), FALSE);
		i++;
	}
	stack->size = i;
	return (TRUE);
}

t_bool	ft_stack_parser(t_stack *stack, int argc, char *argv[])
{
	long	*parsed_nums;
	char	**splited_args;

	if (argc < 2)
		return (FALSE);
	if (argc == 2)
		splited_args = ft_split(argv[1], ' ');
	else
		splited_args = argv + 1;
	if (!splited_args)
		return (FALSE);
	parsed_nums = ft_args_to_long(splited_args, argc - 1);
	ft_free_split(splited_args);
	if (!parsed_nums)
		return (FALSE);
	if (!ft_fill_stack(stack, parsed_nums))
		return (free(parsed_nums), FALSE);
	return (TRUE);
}
