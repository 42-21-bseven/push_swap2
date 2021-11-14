/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseven <bseven@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:16 by bseven            #+#    #+#             */
/*   Updated: 2021/11/14 18:36:18 by bseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_a_to_b(t_all *all, int bit)
{
	int	label;

	while (((all->a_stack->index) >> bit & 1) == 0)
		push_stack(&all->b_stack, &all->a_stack, 'b');
	label = all->a_stack->index;
	rotate_stack(&all->a_stack, 'a');
	while (all->a_stack->index != label)
	{
		if (((all->a_stack->index) >> bit & 1) == 0)
			push_stack(&all->b_stack, &all->a_stack, 'b');
		else
			rotate_stack(&all->a_stack, 'a');
	}
}

void	push_from_b_to_a(t_all *all)
{
	while (all->b_stack)
		push_stack(&all->a_stack, &all->b_stack, 'a');
}

void	sort_alg(t_all *all)
{
	int	bit;

	bit = 0;
	while (!(is_sorted(all->a_stack)))
	{
		push_from_a_to_b(all, bit);
		push_from_b_to_a(all);
		bit++;
	}
}
