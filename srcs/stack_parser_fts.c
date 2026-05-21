/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parser_fts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:25:39 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/21 12:31:34 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static t_bool	ft_add_to_stack(t_stack *stack, t_number *n_to_add)
{
	t_number	*last_n;

	last_n = stack->top;
	while (last_n->next_n)
		last_n = last_n->next_n;
	last_n->next_n = n_to_add;
	return (TRUE);
}

static t_bool	ft_fill_stack(t_stack *stack, long *n_to_fill, int size)
{
	t_number	*tmp_n;
	int			i;

	i = 0;
	while (i < size)
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
	t_bool	is_splited;
	long	*parsed_nums;
	char	**splited_args;
	int		size;

	if (argc < 2)
		return (FALSE);
	splited_args = ft_get_args(argc, argv, &is_splited);
	if (!splited_args)
		return (FALSE);
	size = ft_count_args(splited_args);
	parsed_nums = ft_args_to_long(splited_args, size);
	if (is_splited)
		ft_free_split(splited_args);
	if (!parsed_nums)
		return (FALSE);
	if (ft_have_duplicates(parsed_nums, size)
		|| !ft_fill_stack(stack, parsed_nums, size))
		return (free(parsed_nums), FALSE);
	return (free(parsed_nums), TRUE);
}
