/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algrt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:03:47 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/20 13:07:41 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

static	int	ft_get_index(t_stack **stack, int num)
{
	t_stack	*head;
	int		has_min;

	head = *stack;
	has_min = 0;
	while (head)
	{
		if (head->content < num)
			has_min++;
		head = head->next;
	}
	return (has_min);
}

static int	ft_max_bits(t_stack	**stack)
{
	t_stack	*head;
	int		get_index;
	int		max_bits;

	head = *stack;
	get_index = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > get_index)
			get_index = head->index;
		head = head->next;
	}
	while ((get_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_index_stack(t_stack **stack)
{
	t_stack	*mini;

	mini = *stack;
	while (mini)
	{
		mini->index = ft_get_index(stack, mini->content);
		mini = mini->next;
	}
}

void	ft_radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*head;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head = *a;
	size = ft_lstsize(head);
	max_bits = ft_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (ft_lstsize(*b) != 0)
			pa(a, b);
		i++;
	}
}
