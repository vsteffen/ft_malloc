#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libsrcs/libft/includes/libft.h"

int			main(int ac, char **av)
{
	// char	*str1;
	// char	*str2;
	// char	*str3;
	//
	// str1 = (char*)malloc(1024);
	// str2 = (char*)malloc(1024);
	// str3 = (char*)malloc(1024);
	//
	// // free(str2);
	// str2 = realloc(str2, 25);
	// str2 = realloc(str2, 1052);
	// // free(str2);
	// str3 = (char*)malloc(24);
	// str2[0] = 'q';
	// str2[1] = '\0';
	// ft_putstr("+-+-+-+-+-+-+-+-+-+-+-+\n");
	// ft_putstr(str2); ft_putchar('\n');
	// ft_putstr("+-+-+-+-+-+-+-+-+-+-+-+\n");

	char	*ptr;
	char	*ptr1;
	char	*ptr2;
	char	*ptr3;
	char	*ptr4;
	char	*ptr5;
	char	*ptr6;
	char	*ptr7;
	char	*ptr8;
	char	*ptr9;
	char	*ptr10;
	char	*ptr11;
	char	*ptr12;
	char	*ptr13;
	char	*ptr14;
	char	*ptr15;
	char	*ptr16;

	// ptr = malloc(1024);
	// // free(0x7FC7CE400090);
	// // free(0x7FC7CE400080);
	// // free(0x7FC7CE4000B0);
	// ptr = malloc(32);
	// // free(0x7FC7CE400160);
	// // free(0x7FC7CE800000);
	// ptr = malloc(32);
	// // free(0x7FC7CE4004D0);
	// // free(0x7FC7CE400100);
	// // free(0x7FC7CE4004F0);
	// ptr1 = malloc(8);// ->ptr1
	// ptr2 = malloc(8);// ->ptr2
	// ptr3 = malloc(8);// ->ptr3
	// ptr4 = malloc(24);// ->ptr4
	// free(ptr1);
	// free(ptr2);
	// free(ptr3);
	// // free(0x7FC7CE402110);
	// ptr5 = malloc(8);// ->ptr5
	// ptr6 = malloc(8);// ->ptr6
	// ptr7 = malloc(8);// ->ptr7
	// ptr = malloc(24);// ->0x100FC8248
	// free(ptr5);
	// free(ptr6);
	// free(ptr7);
	// // free(0x7FC7CE402130);
	// ptr8 = malloc(8);// ->ptr8
	// ptr9 = malloc(8);// ->ptr9
	// ptr10 = malloc(8);// ->ptr10
	// ptr = realloc(ptr4, 32);
	// ptr11 = malloc(32);// ->ptr11
	// // free(0x100FC81C8);
	// free(ptr8);
	// free(ptr9);
	// free(ptr10);
	// // free(0x7FC7CE402150);
	// ptr12 = malloc(8);// ->ptr12
	// ptr13 = malloc(8);// ->ptr13
	// ptr14 = malloc(8);// ->ptr14
	// ptr = realloc(ptr11, 40);
	// free(ptr12);
	// free(ptr13);
	// free(ptr14);
	// // free(0x7FC7CE402170);
	// ptr = malloc(16);// ->0x100FC8320
	// ptr = malloc(45);// ->0x100FC8360
	// ptr = malloc(232);// ->0x105679030
	// ptr = malloc(45);// ->0x100FC83BD
	// ptr = malloc(50);// ->0x100FC841A
	// ptr = malloc(47);// ->0x100FC847C
	// ptr = malloc(15);// ->0x100FC84DB
	// ptr = malloc(64);// ->0x100FC851A
	// ptr = malloc(49);// ->0x100FC858A
	// ptr = malloc(67);// ->0x100FC85EB
	// ptr = malloc(52);// ->0x100FC865E
	// ptr = malloc(54);// ->0x100FC86C2
	// ptr = malloc(12);// ->0x100FC8728
	// ptr = malloc(45);// ->0x100FC8764
	// ptr = malloc(94);// ->0x105679148
	// ptr = malloc(118);// ->0x1056791D6
	// // free(0x0);
	// ptr = malloc(16);// ->0x100FC87C1
	// ptr = malloc(64);// ->0x100FC8801
	// ptr = malloc(14);// ->0x100FC8871
	// ptr = realloc(0x0, 256);
	// ptr15 = malloc(256);// ->ptr15
	// free(ptr15);
	// ptr = realloc(0x0, 256);
	// ptr16 = malloc(256);// ->ptr16
	// free(ptr16);


	ptr1 = malloc(8); // -->ptr1
	memset(ptr1, 75, 8);
	ptr2 = malloc(16); // -->ptr2
	memset(ptr2, 75, 16);
	free(ptr1);
	ptr = malloc(16); // -->0x100380078
	memset(ptr, 75, 16);
	ptr = malloc(32); // -->0x1003800A8
	memset(ptr, 75, 32);
	ptr = malloc(32); // -->0x1003800E8
	memset(ptr, 75, 32);
	ptr = malloc(32); // -->0x100380128
	memset(ptr, 75, 32);
	ptr = malloc(32); // -->0x100380168
	memset(ptr, 75, 32);
	ptr = malloc(8); // -->0x1003801A8
	memset(ptr, 75, 8);
	ptr = malloc(27); // -->0x1003801D0
	memset(ptr, 75, 27);
	ptr = malloc(22); // -->0x10038020B
	memset(ptr, 75, 22);
	ptr = malloc(14); // -->0x100380241
	memset(ptr, 75, 14);
	ptr = malloc(45); // -->0x10038026F
	memset(ptr, 75, 45);
	ptr = malloc(194); // -->0x1003802BC
	memset(ptr, 75, 194);
	ptr = malloc(45); // -->0x10038039E
	memset(ptr, 75, 45);
	ptr = malloc(50); // -->0x1003803EB
	memset(ptr, 75, 50);
	ptr = malloc(47); // -->0x10038043D
	memset(ptr, 75, 47);
	ptr = malloc(14); // -->0x10038048C
	memset(ptr, 75, 14);
	ptr = malloc(64); // -->0x1003804BA
	memset(ptr, 75, 64);
	ptr = malloc(49); // -->0x10038051A
	memset(ptr, 75, 49);
	ptr = malloc(67); // -->0x10038056B
	memset(ptr, 75, 67);
	ptr = malloc(52); // -->0x1003805CE
	memset(ptr, 75, 52);
	ptr = malloc(54); // -->0x100380622
	memset(ptr, 75, 54);
	ptr = malloc(32); // -->0x100380678
	memset(ptr, 75, 32);
	free(ptr2);
	ptr = malloc(94); // -->0x1003806B8
	memset(ptr, 75, 94);
	ptr = malloc(16); // -->0x100380736
	memset(ptr, 75, 16);
	ptr = malloc(64); // -->0x100380766
	memset(ptr, 75, 64);
	ptr = malloc(14); // -->0x1003807C6
	memset(ptr, 75, 14);
	ptr3 = realloc(0x0, 256);
	memset(ptr3, 75, 256);
	write(1, "+-+-+-+-+\n", 10);
	write(1, ptr3, 255);
	write(1, "\n+-+-+-+-+\n", 11);
	free(ptr3);
	ptr = malloc(16); // -->0x1003807F4
	memset(ptr, 75, 16);
	ptr = malloc(16); // -->0x100380824
	memset(ptr, 75, 16);
	show_alloc_mem();

	ft_putstr("\nSearching size optimisation:\n");
	for (int i = 1; i < 30; i++) {
		ft_putchar('\n');
		print_debug_size_t((size_t)i, "i");
		print_debug_size_t((i * getpagesize() - 3200) / 100	, "space left");
	}

	return (0);
}
