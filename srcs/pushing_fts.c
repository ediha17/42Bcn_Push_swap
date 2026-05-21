/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 00:35:41 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/21 11:28:58 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_push(t_stack *stack_1, t_stack *stack_2)
{
	t_number	*top_s2;

	if (!stack_2 || !stack_2->top)
		return ;
	top_s2 = stack_2->top;
	stack_2->top = stack_2->top->next_n;
	top_s2->next_n = stack_1->top;
	stack_1->top = top_s2;
	stack_2->size--;
	stack_1->size++;
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
