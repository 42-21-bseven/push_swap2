#include "push_swap.h"

int main(int ac, char **av)
{
	t_all all;
	t_list *curr;
	int flag;
	t_list *test;

	flag = 33;
	if (ac < 2)
		return (put_err("! Wrong args."));







	init_args(&all);
	if (init_list(&all, ac, av))
		return (1);

//	sort(&all);


//	all.current_len = current_len(all.a_stack);

/*	while (flag)
	{
		while (test)
		{
			if (test->next && test->vol > test->next->vol)
				rotate_stack(&test);
			else
				push_stack(&all.b_stack, &test);
		}
		if (test == NULL)
			flag = 0;
	}
*/
	curr = all.a_stack;
	printf("stack A:\t");
	while (curr)
	{
		printf("%d\t", curr->vol);
		curr = curr->next;
	}
	curr = all.b_stack;
	printf("\nstack B:\t");
	while (curr)
	{
		printf("%d\t", curr->vol);
		curr = curr->next;
	}
	printf("\n");
	return (0);
}