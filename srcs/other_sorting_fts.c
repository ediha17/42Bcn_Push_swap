/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sorting_fts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:21:07 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/18 14:37:47 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	ft_is_sorted(t_stack *stack_a)
{
	t_number	*tmp;

	tmp = stack_a->top;
	while (tmp && tmp->next_n)
	{
		if (tmp->value > tmp->next_n->value)
			return (FALSE);
		tmp = tmp->next_n;
	}
	return (TRUE);
}

void	ft_sort_three(t_stack	*stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->value;
	second = stack->top->next_n->value;
	third = stack->top->next_n->next_n->value;
	if (first < second && second > third)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (first > second && second < third)
		ft_sa(stack);
	else if (first < second && second > third)
		ft_rra(stack);
	else if (first > second && second > third)
	{	
		ft_sa(stack);
		ft_rra(stack);
	}
	else
		ft_ra(stack);
}

void	ft_start_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size > 3 && stack_a->size <= 5)
		ft_small_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}
