/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseven <bseven@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:41 by bseven            #+#    #+#             */
/*   Updated: 2021/11/14 18:36:43 by bseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **list, char ab)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = *list;
		if ((*list)->next)
		{
			*list = (*list)->next;
			tmp->next = (*list)->next;
			(*list)->next = tmp;
		}
	}
	ft_write("s", ab);
}

void	push_stack(t_list **dest, t_list **srcs, char ab)
{
	t_list	*temp;

	if (*srcs)
	{
		temp = *srcs;
		if ((*srcs)->next)
			(*srcs) = (*srcs)->next;
		else
			(*srcs) = NULL;
		temp->next = NULL;
		ft_lstadd_front(dest, temp);
	}
	ft_write("p", ab);
}

void	rotate_stack(t_list **list, char ab)
{
	t_list	*temp;

	if (*list)
	{
		temp = (*list);
		if ((*list)->next)
		{
			(*list) = (*list)->next;
			temp->next = NULL;
			ft_lstadd_back(list, temp);
		}
	}
	ft_write("r", ab);
}

void	rev_rotate_stack(t_list **list, char ab)
{
	t_list	*temp;
	t_list	*curr;

	if (*list && (*list)->next)
	{
		temp = ft_lstlast(*list);
		curr = *list;
		while (curr->next && curr->next->next)
			curr = curr->next;
		curr->next = NULL;
		temp->next = *list;
		*list = temp;
	}
	ft_write("rr", ab);
}
