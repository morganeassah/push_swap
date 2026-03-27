/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:14:47 by massah            #+#    #+#             */
/*   Updated: 2026/01/03 18:16:46 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	ft_error(void);
void	free_tab(char **tab);
void	free_exit(char **tmp, t_stack **a);
void	addfirst(t_stack **a, int nbr, int index);
void	addlast(t_stack **a, int nbr);
void	lstdel(t_stack **stack, t_stack *todel);
void	free_all(t_stack **a);
void	check_double(int ac, char **av);
void	sa_sb_rra_rrb(t_stack **stack);
void	ft_sa_sb(t_stack **stack, int ab);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_ra_rb(t_stack **stack, int ab);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra_rrb(t_stack **stack, int ab);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b, t_stack *push);
void	ft_pa(t_stack **a, t_stack **b, t_stack *push);
void	ft_sort(t_stack **a, t_stack **b);
void	put_index(t_stack *stack, int *tab);
void	ft_swap(int *tab, int i, int j);
void	ft_sort_three(t_stack **stack);
void	sort_2(t_stack **a, t_stack **b);
void	ft_sort_big(t_stack **a, t_stack **b);
void	do_rotations(t_stack **a, t_stack **b, int index);
void	end_b(t_stack **b, int index);
void	end_a(t_stack **a, int target);

int		is_sorted(t_stack *a);
int		*ft_bubble_sort(t_stack *stack);
int		check_double2(char **str, int *error);
int		is_cheapest(t_stack *a, t_stack *b);
int		target_a(t_stack *a, int b_index);
int		cost(t_stack *stack, int index);
int		lstsize(t_stack *a);
int		ft_pos(t_stack *a, int index);
int		ft_atoi2(const char *str, int *error);
int		ft_is_min(t_stack *a);

t_stack	*fill_stack(int ac, char **av);
t_stack	*fill_stack2(char **av);

#endif
