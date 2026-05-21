/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:19:56 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/21 11:30:21 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int ft_get_max_bits(t_stack *stack_a)
{
	t_number	*tmp;
	int			max_index;
	int			max_bits;

	tmp = stack_a->top;
	max_index = 0;
	max_bits = 0;
	while (tmp->next_n)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next_n;		
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	max_bits = ft_get_max_bits(stack_a);
	size = stack_a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->top->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
