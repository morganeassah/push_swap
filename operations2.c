/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:55:22 by massah            #+#    #+#             */
/*   Updated: 2026/01/23 13:55:26 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	first->next = first;
	first->prev = second;
	second->next = first;
	second->prev = first;
	*stack = second;
	write (1, "sa/n", 1);
}

void	ft_rra_rrb(t_stack **stack, int ab)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
	if (ab == 0)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (!a || !*a || ((*a)->next == *a) || !*b | ((*b)->next == *b))
		return ;
	*a = (*a)->prev;
	*b = (*b)->prev;
	write(1, "rrr\n", 4);
}

void	ft_pa(t_stack **a, t_stack **b, t_stack *push)
{
	addfirst(a, push->nbr, push->index);
	lstdel(b, push);
	write(1, "pa\n", 3);
}
