/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:16:13 by massah            #+#    #+#             */
/*   Updated: 2026/01/21 17:16:17 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*alloc_tab(int size, t_stack *stack)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = stack->nbr;
		stack = stack->next;
		i++;
	}
	return (tab);
}

int	ft_is_min(t_stack *a)
{
	int		i;
	int		min;
	int		size;
	t_stack	*tmp;

	size = lstsize(a);
	i = 1;
	min = a->index;
	tmp = a;
	while (i < size)
	{
		tmp = tmp->next;
		if (min > tmp->index)
			min = tmp->index;
		i++;
	}
	return (min);
}

void	ft_swap(int *tab, int i, int j)
{
	int	tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

int	*ft_bubble_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	*tab;
	int	size;

	size = lstsize(stack);
	tab = NULL;
	tab = alloc_tab(size, stack);
	if (!tab)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (tab[j] > tab[j + 1])
				ft_swap(tab, j, j + 1);
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_pos(t_stack *a, int index)
{
	t_stack	*tmp;
	int		pos;
	int		size;

	tmp = a;
	pos = 0;
	size = lstsize(a);
	while (tmp->index != index && pos < size)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}
