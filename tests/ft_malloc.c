#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			main(int ac, char **av)
{
	void	*ptr;

	// ptr = malloc(1);
	ptr = malloc(1);
	ptr = malloc(2);
	ptr = malloc(3);
	ptr = malloc(40);
	for (int i = 0; i < 120; i++)
	{
		ptr = malloc(40);
		// ptr = malloc(30);
	}
	show_alloc_mem();
	return (0);
}
