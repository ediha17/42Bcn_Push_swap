/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sorting_fts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:02:43 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/18 21:29:51 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_find_lowest(t_stack *stack)
{
	t_number	*tmp;
	int			lowest_val;
	int			lowest_pos;
	int			i;

	tmp = stack->top;
	lowest_val = tmp->value;
	lowest_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < lowest_val)
		{
			lowest_val = tmp->value;
			lowest_pos = i;
		}
		i++;
		tmp = tmp->next_n;
	}
	return (lowest_pos);
}
