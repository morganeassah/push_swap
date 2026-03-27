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

int	is_cheapest(t_stack *a, t_stack *b)
{
	int		cheapest_cost;
	int		cheapest_index;
	int		size;
	int		total;
	t_stack	*tmp;

	tmp = b;
	size = lstsize(b);
	cheapest_cost = INT_MAX;
	while (size--)
	{
		total = cost(b, tmp->index) + cost(a, target_a(a, tmp->index));
		if (total < cheapest_cost)
		{
			cheapest_cost = total;
			cheapest_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (cheapest_index);
}

int	target_a(t_stack *a, int b_index)
{
	int		target;
	int		size;
	int		i;
	t_stack	*tmp;

	tmp = a;
	target = INT_MAX;
	size = lstsize(a);
	i = 0;
	while (i++ < size)
	{
		if (tmp->index > b_index && tmp->index < target)
			target = tmp->index;
		tmp = tmp->next;
	}
	if (target == INT_MAX)
		return (ft_is_min(a));
	return (target);
}

int	cost(t_stack *stack, int index)
{
	int	size;
	int	pos;

	size = lstsize(stack);
	pos = ft_pos(stack, index);
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

void	do_rotations(t_stack **a, t_stack **b, int index)
{
	int	target;
	int	pos_a;
	int	pos_b;

	if (!a || !b || !*a || !*b)
		return ;
	target = target_a(*a, index);
	pos_a = ft_pos(*a, target);
	pos_b = ft_pos(*b, index);
	while ((pos_a <= lstsize(*a) / 2
			&& pos_b <= lstsize(*b) / 2 && pos_a && pos_b)
		|| (pos_a > lstsize(*a) / 2 && pos_b > lstsize(*b) / 2))
	{
		if (pos_a <= lstsize(*a) / 2 && pos_b <= lstsize(*b) / 2)
			ft_rr(a, b);
		else
			ft_rrr(a, b);
		pos_a = ft_pos(*a, target);
		pos_b = ft_pos(*b, index);
	}
	while ((*a)->index != target)
		end_a(a, target);
	while ((*b)->index != index)
		end_b(b, index);
}

void	end_b(t_stack **b, int index)
{
	if (ft_pos(*b, index) <= lstsize(*b) / 2)
		ft_ra_rb(b, 1);
	else
		ft_rra_rrb(b, 1);
}
