/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:33:40 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/18 20:23:48 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

int	ft_sort3_cases(t_stack **a)
{
	t_stack	*lastnode;
	t_stack	*middlenode;

	lastnode = ft_lstlast(*a);
	middlenode = (*a)->next;
	if ((*a)->content < lastnode->content)
	{
		if (middlenode->content < lastnode->content)
			return (1);
		return (3);
	}
	else
	{
		if ((middlenode->content > lastnode->content)
			&& middlenode->content < (*a)->content)
			return (2);
		else if ((middlenode->content > lastnode->content)
			&& middlenode->content > (*a)->content)
			return (4);
		else
			return (5);
	}
}

void	ft_sort2(t_stack **a)
{
	if (ft_lstsize(*a) == 2 && ft_status_sort(*a) == 1)
		sa(a);
	else
		ft_error();
}

void	ft_sort3(t_stack **a)
{
	if (ft_lstsize(*a) == 3 && ft_status_sort(*a) == 1)
	{
		if (ft_sort3_cases(a) == 1)
			sa(a);
		else if (ft_sort3_cases(a) == 2)
		{
			sa(a);
			rra(a);
		}
		else if (ft_sort3_cases(a) == 3)
		{
			sa(a);
			ra(a);
		}
		else if (ft_sort3_cases(a) == 4)
			rra(a);
		else if (ft_sort3_cases(a) == 5)
			ra(a);
	}
	else
		ft_error();
}

void	ft_sort4(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 4 && ft_status_sort(*a) == 1)
	{
		ft_putmin_top(a);
		if (ft_status_sort(*a) == 0)
			return ;
		pb(a, b);
		ft_sort3(a);
		pa(a, b);
	}
}

void	ft_sort5(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 5 && ft_status_sort(*a) == 1)
	{
		ft_putmin_top(a);
		pb(a, b);
		ft_sort4(a, b);
		pa(a, b);
	}
}
