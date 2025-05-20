/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:26:38 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/12 16:30:38 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = *stack;
	temp = NULL;
	while (first->next != NULL)
	{
		temp = first;
		first = first->next;
	}
	temp->next = NULL;
	first->next = second;
	*stack = first;
}

void	rra(t_stack **a)
{
	ft_reverse(a);
	if (write(1, "rra\n", 4) < 0)
	{
		ft_free(a);
		ft_error();
	}
}

void	rrb(t_stack **b)
{
	ft_reverse(b);
	if (write(1, "rrb\n", 4) < 0)
	{
		ft_free(b);
		ft_error();
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse(a);
	ft_reverse(b);
	if (write(1, "rrr\n", 4) < 0)
	{
		ft_free(a);
		ft_free(b);
		ft_error();
	}
}
