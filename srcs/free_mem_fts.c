/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_fts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:37:16 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/16 14:59:23 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_number	*tmp_n;

	while (stack->top)
	{
		tmp_n = stack->top;
		stack->top = stack->top->next_n;
		free(tmp_n);
	}
	stack->size = 0;
}

void	ft_free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
