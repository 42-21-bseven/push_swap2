/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseven <bseven@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:24 by bseven            #+#    #+#             */
/*   Updated: 2021/11/14 18:36:26 by bseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_all *all, t_list *steak)
{
	int	i;

	while (steak)
	{
		i = 0;
		while (i < all->start_len)
		{
			if (all->mass[i] == steak->vol)
			{
				steak->index = i;
				break ;
			}
			i++;
		}
		steak = steak->next;
	}
	return (0);
}

int	min_index(t_list *steak)
{
	int	min_order;

	min_order = steak->index;
	while (steak != NULL)
	{
		if (steak->index < min_order)
			min_order = steak->index;
		steak = steak->next;
	}
	return (min_order);
}

int	max_index(t_list *steak)
{
	ft_lstlast(steak);
	return (steak->index);
}
