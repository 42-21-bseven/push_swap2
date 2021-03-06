/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseven <bseven@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:32:26 by bseven            #+#    #+#             */
/*   Updated: 2021/11/14 18:33:28 by bseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_args(t_all *all)
{
	all->start_len = all->argc - 1;
	all->a_stack = NULL;
	all->b_stack = NULL;
	all->mass = NULL;
}

int	init_array(t_all *all, t_list *steak, char **av)
{
	int	i;

	i = 0;
	all->mass = malloc(sizeof (int) * all->start_len);
	while (steak)
	{
		all->mass[i++] = steak->vol;
		steak = steak->next;
	}
	return (0);
}
