/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_fts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:27:43 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/20 21:01:26 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	t_number	*first;
	t_number	*last;

	if (!stack || !stack->top || !stack->top->next_n)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next_n)
		last = last->next_n;
	last->next_n = first;
	stack->top = first->next_n;
	first->next_n = NULL;
}

void	ft_ra(t_stack *stack)
{
	ft_rotate(stack);
	write(1, "ra\n", 3);
}
