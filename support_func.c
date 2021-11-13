#include "push_swap.h"

int	put_err(char *str)
{
	printf("ERROR%s\n", str);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

void ft_write(char *psr, char ab)
{
	write (1, psr, ft_strlen(psr));
	write (1, &ab, 1);
	write(1, "\n", 1);
}

void bub_sort(int **arr, int len)
{
	int i;
	int j;
	int n;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if ((*arr)[i] > (*arr)[j])
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
