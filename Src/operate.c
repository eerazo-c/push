/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:30 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/20 14:38:44 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

int	ft_operate(t_stack **a, t_stack **b)
{
	if (ft_status_sort(*a) == 0)
	{
		ft_free(a);
		exit(0);
	}
	if (ft_lstsize(*a) == 2)
		ft_sort2(a);
	else if (ft_lstsize(*a) == 3)
		ft_sort3(a);
	else if (ft_lstsize(*a) == 4)
		ft_sort4(a, b);
	else if (ft_lstsize(*a) == 5)
		ft_sort5(a, b);
	else if (ft_lstsize(*a) > 5)
		ft_radix_sort(a, b);
	if (a)
		ft_free(a);
	if (b)
		ft_free(b);
	return (0);
}

int	ft_status_sort(t_stack *a)
{
	int	status;

	status = 0;
	while (a->next && status == 0)
	{
		if (a->content > a->next->content)
			status = 1;
		a = a->next;
	}
	return (status);
}

int	ft_min_locator(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		min_val;
	int		min_pos;

	min_val = (*stack)->content;
	tmp = (*stack);
	min_pos = 0;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->content < min_val)
		{
			min_val = tmp->content;
			min_pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (tmp->content < min_val)
	{
		min_pos = i;
		min_val = tmp->content;
	}
	return (min_pos);
}

void	ft_putmin_top(t_stack **a)
{
	int	min_pos;
	int	len;
	int	up_i;
	int	down_i;

	min_pos = ft_min_locator(a);
	len = ft_lstsize(*a);
	up_i = min_pos;
	down_i = len - min_pos;
	if (up_i <= down_i)
	{
		while (up_i > 0)
		{
			ra(a);
			up_i--;
		}
	}
	else if (down_i < up_i)
	{
		while (down_i > 0)
		{
			rra(a);
			down_i--;
		}
	}
}
