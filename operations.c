/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:20:51 by massah            #+#    #+#             */
/*   Updated: 2026/01/22 20:20:53 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_stack **stack, int ab)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	if (lstsize(*stack) == 2)
		swap_two(stack);
	first = *stack;
	second = first->next;
	third = second->next;
	last = first->prev;
	last->next = second;
	second->next = first;
	second->prev = last;
	first->prev = second;
	first->next = third;
	third->prev = first;
	*stack = second;
	if (ab == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa_sb(a, 0);
	ft_sa_sb(b, 1);
	write(1, "ss\n", 3);
}

void	ft_ra_rb(t_stack **stack, int ab)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
	if (ab == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (!a || !*a || ((*a)->next == *a) || !*b | ((*b)->next == *b))
		return ;
	*a = (*a)->next;
	*b = (*b)->next;
	write(1, "rr\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, t_stack *push)
{
	addfirst(b, push->nbr, push->index);
	lstdel(a, push);
	write(1, "pb\n", 3);
}
