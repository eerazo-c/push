/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:00:31 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/03 15:19:28 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

int	check_dup(char **av)
{
	int	i;
	int	k;

	i = 1;
	while (av[i] != NULL)
	{
		k = i + 1;
		while (av[k] != NULL)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[k]))
				return (-1);
			k++;
		}
		i++;
	}
	return (0);
}

int	num_check(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-') || (av[i] == '+'))
		i++;
	if (av[i] == '\0')
		return (-1);
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_limit_check(long nb, t_stack **a)
{
	if (!(nb < INT_MAX && nb > INT_MIN))
	{
		ft_free(a);
		ft_error();
	}
	return (nb);
}

void	ft_free(t_stack **stack)
{
	t_stack	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
}

int	ft_error(void)
{
	write (1, "\e[0;31mError\e[0m\n", 17);
	exit(1);
	return (-1);
}
