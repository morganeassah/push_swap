/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:52:30 by massah            #+#    #+#             */
/*   Updated: 2026/01/13 19:54:55 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (NULL);
	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	lstsize(t_stack *a)
{
	int		i;
	t_stack	*start;

	if (!a)
		return (0);
	i = 0;
	start = a;
	while (a)
	{
		i++;
		a = a->next;
		if (a == start)
			break ;
	}
	return (i);
}
