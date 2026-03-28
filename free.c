/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:46:45 by massah            #+#    #+#             */
/*   Updated: 2026/03/28 19:46:48 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(char **tmp, t_stack **a)
{
	free_tab(tmp);
	free(tmp);
	free_all(a);
	ft_error();
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

void	free_all(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*start;

	if (!a || !*a)
		return ;
	start = *a;
	current = start->next;
	while (current != start)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(start);
	*a = NULL;
}
