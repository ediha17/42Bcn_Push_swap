/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:40:22 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/18 17:06:54 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

/*+==========================+
  |       EXTERN LIBS        |
  +==========================+*/

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*+==========================+
  |          MACROS          |
  +==========================+*/

# define TRUE 1
# define FALSE 0

/*+==========================+
  |        VARIABLES         |
  +==========================+*/

typedef int	t_bool;

/*+==========================+
  |         STRUCTS          |
  +==========================+*/

typedef struct s_number
{
	int				value;
	int				index;
	struct s_number	*next_n;	
}	t_number;

typedef struct s_stack
{
	t_number	*top;
	int			size;
}	t_stack;

/*+==========================+
  |        FUNCTIONS         |
  +==========================+*/

int		main(int argc, char *argv[]);
int		ft_count_args(char **args);
t_bool	ft_stack_parser(t_stack *stack, int argc, char *argv[]);
void	ft_free_stack(t_stack *stack);
void	ft_start_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_print_error(void);
t_bool	ft_isdigit(int c);
char	**ft_split(char *str, char separator);
char	**ft_get_args(int argc, char *argv[], t_bool *is_splited);
void	ft_free_split(char **args);
long	ft_atol(char *str, t_bool *err_flag);
long	*ft_args_to_long(char **args, int size);
t_bool	ft_nums_checker(char **args);
t_bool	ft_have_duplicates(long *nums, int size);

#endif
