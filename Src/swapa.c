/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:52:08 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/18 19:36:41 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	ft_moves(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
}

void	sa(t_stack	**a)
{
	if (*a == NULL)
		return ;
	ft_moves(a);
	if (write(1, "sa\n", 3) < 0)
	{
		ft_free(a);
		ft_error();
	}
}

void	sb(t_stack **b)
{
	if (*b == NULL)
		return ;
	ft_moves(b);
	if (write(1, "sb\n", 3) < 0)
	{
		ft_free(b);
		ft_error();
	}
}

void	ss(t_stack **a, t_stack **b)
{
	ft_moves(a);
	ft_moves(b);
	if (write(1, "ss\n", 3) < 0)
	{
		ft_free(a);
		ft_free(b);
		ft_error();
	}
}
