#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			main(int ac, char **av)
{
	void	*ptr;

	// ptr = malloc(1);
	ptr = malloc(1);
	ptr = malloc(2);
	// ptr = malloc(3);
	ptr = malloc(40);
	for (int i = 0; i < 62; i++)
	{
		// ptr = malloc(40);
		if (i == 61)
			show_alloc_mem();
		ptr = malloc(40);
	}
	// show_alloc_mem();
	return (0);
}


/*

3906 + 128 + 46


t_block_mem = 24

*/
