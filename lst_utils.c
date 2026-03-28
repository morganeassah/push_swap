/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:48:11 by massah            #+#    #+#             */
/*   Updated: 2026/01/04 15:48:22 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addfirst(t_stack **stack, int nbr, int index)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->nbr = nbr;
	new->index = index;
	if (!*stack)
	{
		new->prev = new;
		new->next = new;
		*stack = new;
		return ;
	}
	last = (*stack)->prev;
	new->next = *stack;
	new->prev = last;
	last->next = new;
	(*stack)->prev = new;
	*stack = new;
}

void	addlast(t_stack **stack, int nbr)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	new->index = -1;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*stack)->prev;
	new->next = *stack;
	last->next = new;
	new->prev = last;
	(*stack)->prev = new;
}

void	lstdel(t_stack **stack, t_stack *todel)
{
	if (!stack || !*stack || !todel)
		return ;
	if (todel == todel->next)
	{
		*stack = NULL;
		free(todel);
		return ;
	}
	todel->prev->next = todel->next;
	todel->next->prev = todel->prev;
	if (*stack == todel)
		*stack = todel->next;
	free(todel);
}
