#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			main(int ac, char **av)
{
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;

	ptr1 = malloc(1);
	ptr2 = malloc(2);
	ptr3 = malloc(3);

	free(ptr2);
	// ptr2 = malloc(3);

	// ptr = malloc(3);
	// ptr = malloc(40);
	// for (int i = 0; i < 10000; i++)
	// {
	// 	// ptr = malloc(40);
	// 	// if (i == 61)
	// 		// show_alloc_mem();
	// 	ptr = malloc(16);
	// }
	show_alloc_mem();
	return (0);
}


/*

3906 + 128 + 46


t_block_mem = 24

	0	|	1	|	2	|	3	|	4	|	5	|	6	|	7	|	8	|	9	|	10	|	11	|	12	|	13	|	14	|	15	|	16	|	17	|	18	|	19	|	20	|	21	|	22	|	23	|	24	|	25	|	26	|	27	|	18	|

first alloc -> user data located in 0x18
deb metadata second alloc 0x19
deb user next alloc 0x31

10670A000
10676CFC8


*/
