/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseven <bseven@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:51 by bseven            #+#    #+#             */
/*   Updated: 2021/11/14 18:36:52 by bseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_err(char *str)
{
	write(1, "Error\n", ft_strlen("Error\n"));
	return (1);
}

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

void	ft_write(char *psr, char ab)
{
	write (1, psr, ft_strlen(psr));
	write (1, &ab, 1);
	write(1, "\n", 1);
}

void	bub_sort(int **arr, int len)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if ((*arr)[i] < (*arr)[j])
			{
				n = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = n;
			}
			j++;
		}
		i++;
	}
}
