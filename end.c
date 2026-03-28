/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:44:46 by massah            #+#    #+#             */
/*   Updated: 2026/03/28 21:44:47 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_b(t_stack **b, int index)
{
	if (ft_pos(*b, index) <= lstsize(*b) / 2)
		ft_ra_rb(b, 1);
	else
		ft_rra_rrb(b, 1);
}

void	end_a(t_stack **a, int target)
{
	while ((*a)->index != target)
	{
		if (ft_pos(*a, target) > lstsize(*a) / 2)
			ft_rra_rrb(a, 0);
		else
			ft_ra_rb(a, 0);
	}
}
