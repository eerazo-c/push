/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:34:51 by elerazo-          #+#    #+#             */
/*   Updated: 2025/02/17 18:27:57 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/push_swap.h"

void	add_new(t_stack **a, int content)
{
	t_stack	*nodo;
	t_stack	*temp;

	nodo = (t_stack *)malloc(sizeof(t_stack));
	if (nodo == NULL)
		return ;
	nodo->content = content;
	nodo->next = NULL;
	if (*a == NULL)
		*a = nodo;
	else
	{
		temp = *a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nodo;
	}
}

int	ft_lstsize(t_stack	*lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (tmp);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	show_stack(t_stack *a)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = a;
	while (stack != NULL)
	{
		if (stack != NULL)
			ft_printf("node[%i]%d\n", i, stack->content);
		stack = stack->next;
	}
}
