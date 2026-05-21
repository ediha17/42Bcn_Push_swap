/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:42:30 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/21 12:45:21 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (!ft_stack_parser(&a, argc, argv))
		return (ft_free_stack(&a), ft_print_error(), 1);
	ft_start_sort(&a, &b);
	ft_print_stack(&a);
	ft_free_stack(&a);
	return (0);
}
