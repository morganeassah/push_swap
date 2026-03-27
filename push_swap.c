/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:09:14 by massah            #+#    #+#             */
/*   Updated: 2026/01/05 18:39:25 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp->next != a)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	if (lstsize((*a)) <= 3)
	{
		ft_sort_three(a);
		free_all(a);
		return ;
	}
	else
		ft_sort_big(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = fill_stack(ac, av);
	b = NULL;
	ft_sort(&a, &b);
	return (0);
}
