/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:45:51 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/20 00:31:23 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_swap(t_stack	*stack)
{
	t_number	*first;
	t_number	*second;
	t_number	*third;

	if (!stack || !stack->top || !stack->top->next_n)
		return ;
	first = stack->top;
	second = first->next_n;
	third = second->next_n;
	second->next_n = first;
	first->next_n = third;
	stack->top = second;
}

void	ft_sa(t_stack *stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}
