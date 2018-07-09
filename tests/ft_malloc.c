#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libsrcs/libft/includes/libft.h"

int			main(int ac, char **av)
{
	char	*str;
	void	*ptr;
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;
	void	*ptr5;
	void	*ptr6;
	void	*ptr7;
	void	*ptr8;
	void	*ptr9;
	void	*ptr10;
	void	*ptr11;
	void	*ptr12;
	void	*ptr13;
	void	*ptr14;
	void	*ptr15;
	void	*ptr16;

	ptr = malloc(32);
	// free(0x7FC7CE400090);
	// free(0x7FC7CE400080);
	// free(0x7FC7CE4000B0);
	ptr = malloc(32);
	// free(0x7FC7CE400160);
	// free(0x7FC7CE800000);
	ptr = malloc(32);
	// free(0x7FC7CE4004D0);
	// free(0x7FC7CE400100);
	// free(0x7FC7CE4004F0);
	ptr1 = malloc(8);// ->ptr1
	ptr2 = malloc(8);// ->ptr2
	ptr3 = malloc(8);// ->ptr3
	ptr4 = malloc(24);// ->ptr4
	free(ptr1);
	free(ptr2);
	free(ptr3);
	// free(0x7FC7CE402110);
	ptr5 = malloc(8);// ->ptr5
	ptr6 = malloc(8);// ->ptr6
	ptr7 = malloc(8);// ->ptr7
	ptr = malloc(24);// ->0x100FC8248
	free(ptr5);
	free(ptr6);
	free(ptr7);
	// free(0x7FC7CE402130);
	ptr8 = malloc(8);// ->ptr8
	ptr9 = malloc(8);// ->ptr9
	ptr10 = malloc(8);// ->ptr10
	ptr = realloc(ptr4, 32);
	ptr11 = malloc(32);// ->ptr11
	// free(0x100FC81C8);
	free(ptr8);
	free(ptr9);
	free(ptr10);
	// free(0x7FC7CE402150);
	ptr12 = malloc(8);// ->ptr12
	ptr13 = malloc(8);// ->ptr13
	ptr14 = malloc(8);// ->ptr14
	ptr = realloc(ptr11, 40);
	free(ptr12);
	free(ptr13);
	free(ptr14);
	// free(0x7FC7CE402170);
	ptr = malloc(16);// ->0x100FC8320
	ptr = malloc(45);// ->0x100FC8360
	ptr = malloc(232);// ->0x105679030
	ptr = malloc(45);// ->0x100FC83BD
	ptr = malloc(50);// ->0x100FC841A
	ptr = malloc(47);// ->0x100FC847C
	ptr = malloc(15);// ->0x100FC84DB
	ptr = malloc(64);// ->0x100FC851A
	ptr = malloc(49);// ->0x100FC858A
	ptr = malloc(67);// ->0x100FC85EB
	ptr = malloc(52);// ->0x100FC865E
	ptr = malloc(54);// ->0x100FC86C2
	ptr = malloc(12);// ->0x100FC8728
	ptr = malloc(45);// ->0x100FC8764
	ptr = malloc(94);// ->0x105679148
	ptr = malloc(118);// ->0x1056791D6
	// free(0x0);
	ptr = malloc(16);// ->0x100FC87C1
	ptr = malloc(64);// ->0x100FC8801
	ptr = malloc(14);// ->0x100FC8871
	ptr = realloc(0x0, 256);
	ptr15 = malloc(256);// ->ptr15
	free(ptr15);
	ptr = realloc(0x0, 256);
	ptr16 = malloc(256);// ->ptr16
	free(ptr16);

	show_alloc_mem();
	return (0);
}
