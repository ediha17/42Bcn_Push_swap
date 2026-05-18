/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:42:30 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/18 12:20:36 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_print_stack(t_stack	*stack)
{
	t_number	*current;

	if (!stack || !stack->top)
	{
		printf("stack vacio\n");
		return ;
	}
	printf("----------------- INICIO DEL STACK ---------------------\n");
	current = stack->top;
	printf("tamaño del stack: %d\n", stack->size);
	while (current)
	{
		printf("Valor: %d \n", current->value);
		current = current->next_n;
	}
	printf("------------------ FIN DEL STACK -----------------------\n");
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	//t_stack	b;

	a.top = NULL;
	a.size = 0;
	//b.top = NULL;
	//b.size = 0;
	if (!ft_stack_parser(&a, argc, argv))
		return (ft_free_stack(&a), ft_print_error(), 1);
	//ft_start_sort(&a, &b);
	ft_print_stack(&a);
	ft_free_stack(&a);
	return (0);
}
