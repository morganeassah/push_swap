/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:28:20 by massah            #+#    #+#             */
/*   Updated: 2026/01/06 13:34:26 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_sign(const char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	if (**str == '+')
		(*str)++;
	return (1);
}

int	ft_atoi2(const char *str, int *error)
{
	long long int				sign;
	long long int				i;

	i = 0;
	while (*str == ' ' || (*str == '\t' || *str == '\n'
			|| *str == '\f' || *str == '\v' || *str == '\r'))
		str++;
	sign = get_sign(&str);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (*error = 1, 0);
		i = i * 10 + (*str - '0');
		if (i > 2147483648LL)
			return (*error = 1, 0);
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		return (*error = 1, 0);
	return (sign * i);
}

void	check_double(int ac, char **av)
{
	int	i;
	int	j;
	int	val_i;
	int	val_j;
	int	error;

	i = 1;
	error = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			val_i = ft_atoi2(av[i], &error);
			if (error)
				ft_error();
			val_j = ft_atoi2(av[j], &error);
			if (error)
				ft_error();
			if (val_i == val_j)
				ft_error();
			j++;
		}
		i++;
	}
}

int	check_double2(char **str, int *error)
{
	int	i;
	int	j;
	int	val_i;
	int	val_j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			val_i = ft_atoi2(str[i], error);
			if (*error)
				return (0);
			val_j = ft_atoi2(str[j], error);
			if (*error)
				return (0);
			if (val_i == val_j)
				return (*error = 1, 0);
			j++;
		}
		i++;
	}
	return (0);
}
