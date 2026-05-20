/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating_fts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:57:48 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/20 20:59:07 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	t_number	*last;
	t_number	*before_last;

	if (!stack || !stack->top || !stack->top->next_n)
		return ;
	last = stack->top;
	before_last = NULL;
	while (last->next_n)
	{
		before_last = last;
		last = last->next_n;
	}
	last->next_n = stack->top;
	before_last->next_n = NULL;
	stack->top = last;
}

void	ft_rra(t_stack *stack)
{
	ft_reverse_rotate(stack);
	write(1, "rra\n", 4);
}
