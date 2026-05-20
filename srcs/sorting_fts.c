/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:21:07 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/20 22:05:26 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static t_bool	ft_is_sorted(t_stack *stack_a)
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

static void	ft_assign_index(t_stack *stack)
{
	t_number	*current;
	t_number	*cmp;
	int			idx;

	current = stack->top;
	while (current)
	{
		idx = 0;
		cmp = current->next_n;
		while (cmp)
		{
			if (current->value > cmp->value)
				idx++;
			cmp = cmp->next_n;
		}
		current->index = idx;
		current = current->next_n;
	}
}

static void	ft_sort_three(t_stack	*stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->value;
	second = stack->top->next_n->value;
	third = stack->top->next_n->next_n->value;
	if (first > second && first < third && second < third)
		ft_sa(stack);
	else if (first > second && first > third && second > third)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (first > second && first > third && second < third)
		ft_ra(stack);
	else if (first < second && first < third && second > third)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (first < second && first > third && second > third)
		ft_rra(stack);
}

static void	ft_mini_ps(t_stack *stack_a, t_stack *stack_b)
{
	int	position;

	while (stack_a->size > 3)
	{
		position = ft_find_lowest(stack_a);
		if (position <= (stack_a->size / 2))
		{
			while (position > 0)
			{
				ft_ra(stack_a);
				position--;
			}
		}
		else
		{
			while (position < stack_a->size)
			{
				ft_rra(stack_a);
				position++;
			}
		}
		ft_pb(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	return (ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
}

void	ft_start_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		ft_sa(stack_a);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size > 3 && stack_a->size <= 5)
		ft_mini_ps(stack_a, stack_b);
	else
	{
		ft_assign_index(stack_a);
		ft_radix_sort(stack_a, stack_b);
	}
}
