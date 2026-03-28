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

void	sa_sb_rra_rrb(t_stack **stack)
{
	ft_sa_sb(stack, 0);
	ft_rra_rrb(stack, 0);
}

void	sort_2(t_stack **a, t_stack **b)
{
	int	cheapest;

	while (*b != NULL)
	{
		cheapest = is_cheapest(*a, *b);
		do_rotations(a, b, cheapest);
		ft_pa(a, b, *b);
	}
}

void	ft_sort_big(t_stack **a, t_stack **b)
{
	int	*tab;
	int	min;

	tab = ft_bubble_sort(*a);
	if (!tab)
		return ;
	put_index(*a, tab);
	if (is_sorted(*a))
	{
		free_all(a);
		free(tab);
		exit(1);
	}
	while (lstsize(*a) > 3)
	{
		ft_pb(a, b, *a);
	}
	ft_sort_three(a);
	sort_2(a, b);
	min = ft_is_min(*a);
	end_a(a, min);
	free(tab);
}

void	ft_sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	last;

	if (!a || !*a || (*a)->next == *a)
		return ;
	if (lstsize(*a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			ft_sa_sb(a, 0);
		return ;
	}
	first = (*a)->nbr;
	second = (*a)->next->nbr;
	last = (*a)->prev->nbr;
	if (first > second && second > last)
	{
		sa_sb_rra_rrb(a);
	}
	else if (first > last && last > second)
		ft_ra_rb(a, 0);
	else if (first < last && last < second)
	{
		ft_sa_sb(a, 0);
		ft_ra_rb(a, 0);
	}
	else if (second < first && first < last)
		ft_sa_sb(a, 0);
	else if (last < first && first < second)
		ft_rra_rrb(a, 0);
}
