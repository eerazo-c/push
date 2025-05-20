/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:58:40 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/20 14:40:14 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

int	fill_stack(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if ((num_check(av[i]) != -1 && av[i]) \
			&& ((ft_atoi(av[i]) >= INT_MIN) && (ft_atoi(av[i]) <= INT_MAX)))
		{
			add_new(a, ft_atoi(av[i]));
			if (a == NULL)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	ft_index_stack(a);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		exit(0);
	if (fill_stack(ac, av, &a) == -1)
		return (ft_error());
	if (check_dup(av) == -1)
		return (ft_error());
	show_stack(a);
	ft_operate(&a, &b);
	return (0);
}
