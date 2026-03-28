/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:48:05 by massah            #+#    #+#             */
/*   Updated: 2026/01/14 18:52:38 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int ac, char **av)
{
	int		i;
	int		error;
	t_stack	*a;

	a = NULL;
	error = 0;
	if (ac == 2)
		a = fill_stack2(av);
	else
	{
		check_double(ac, av);
		i = 1;
		while (i < ac)
		{
			addlast(&a, ft_atoi2(av[i], &error));
			i++;
		}
	}
	return (a);
}

t_stack	*fill_stack2(char **av)
{
	int		i;
	int		val;
	int		error;
	char	**tmp;
	t_stack	*a;

	a = NULL;
	i = 0;
	error = 0;
	tmp = ft_split(av[1], ' ');
	if (!tmp)
		ft_error();
	check_double2(tmp, &error);
	while (tmp[i])
	{
		val = ft_atoi2(tmp[i], &error);
		if (error)
			free_exit(tmp, &a);
		addlast(&a, val);
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (a);
}

void	put_index(t_stack *stack, int *tab)
{
	int		i;
	int		j;
	int		size;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	size = lstsize(stack);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tmp->nbr == tab[i])
				tmp->index = i;
			tmp = tmp->next;
			j++;
		}
		i++;
	}
}
