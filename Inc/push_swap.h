/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:04:54 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/19 17:59:20 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# <biblioteca.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include "../library/printf/ft_printf.h"
# include "../library/libft/libft.h"

//structura
typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

//prototipo de funciones
int		fill_stack(int ac, char **av, t_stack **a);
int		num_check(char *av);
int		check_dup(char **av);
int		ft_error(void);
void	ft_free(t_stack **a);
int		ft_limit_check(long nb, t_stack **a);
void	ft_free(t_stack **stack);
int		ft_error(void);

//listas
void	add_new(t_stack **a, int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	show_stack(t_stack *a);

//operaciones de mov
void	ft_moves(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rot(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//operate
int		ft_operate(t_stack **a, t_stack **b);
int		ft_status_sort(t_stack *a);
int		ft_min_locator(t_stack **stack);
void	ft_putmin_top(t_stack **a);

//sort cases
void	ft_sort2(t_stack **a);
void	ft_sort3(t_stack **a);
void	ft_sort4(t_stack **a, t_stack **b);
void	ft_sort5(t_stack **a, t_stack **b);
int		ft_sort3_cases(t_stack **a);

//algr
void	ft_index_stack(t_stack **stack);
void	ft_radix_sort(t_stack **a, t_stack **b);

#endif
