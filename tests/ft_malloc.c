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


	// ptr1 = malloc(8); // -->ptr1
	// memset(ptr1, 75, 8);
	// ptr2 = malloc(16); // -->ptr2
	// memset(ptr2, 75, 16);
	// free(ptr1);
	// ptr = malloc(16); // -->0x100380078
	// memset(ptr, 75, 16);
	// ptr = malloc(32); // -->0x1003800A8
	// memset(ptr, 75, 32);
	// ptr = malloc(32); // -->0x1003800E8
	// memset(ptr, 75, 32);
	// ptr = malloc(32); // -->0x100380128
	// memset(ptr, 75, 32);
	// ptr = malloc(32); // -->0x100380168
	// memset(ptr, 75, 32);
	// ptr = malloc(8); // -->0x1003801A8
	// memset(ptr, 75, 8);
	// ptr = malloc(27); // -->0x1003801D0
	// memset(ptr, 75, 27);
	// ptr = malloc(22); // -->0x10038020B
	// memset(ptr, 75, 22);
	// ptr = malloc(14); // -->0x100380241
	// memset(ptr, 75, 14);
	// ptr = malloc(45); // -->0x10038026F
	// memset(ptr, 75, 45);
	// ptr = malloc(194); // -->0x1003802BC
	// memset(ptr, 75, 194);
	// ptr = malloc(45); // -->0x10038039E
	// memset(ptr, 75, 45);
	// ptr = malloc(50); // -->0x1003803EB
	// memset(ptr, 75, 50);
	// ptr = malloc(47); // -->0x10038043D
	// memset(ptr, 75, 47);
	// ptr = malloc(14); // -->0x10038048C
	// memset(ptr, 75, 14);
	// ptr = malloc(64); // -->0x1003804BA
	// memset(ptr, 75, 64);
	// ptr = malloc(49); // -->0x10038051A
	// memset(ptr, 75, 49);
	// ptr = malloc(67); // -->0x10038056B
	// memset(ptr, 75, 67);
	// ptr = malloc(52); // -->0x1003805CE
	// memset(ptr, 75, 52);
	// ptr = malloc(54); // -->0x100380622
	// memset(ptr, 75, 54);
	// ptr = malloc(32); // -->0x100380678
	// memset(ptr, 75, 32);
	// free(ptr2);
	// ptr = malloc(94); // -->0x1003806B8
	// memset(ptr, 75, 94);
	// ptr = malloc(16); // -->0x100380736
	// memset(ptr, 75, 16);
	// ptr = malloc(64); // -->0x100380766
	// memset(ptr, 75, 64);
	// ptr = malloc(14); // -->0x1003807C6
	// memset(ptr, 75, 14);
	// ptr3 = realloc(0x0, 256);
	// memset(ptr3, 75, 256);
	// write(1, "+-+-+-+-+\n", 10);
	// write(1, ptr3, 255);
	// write(1, "\n+-+-+-+-+\n", 11);
	// free(ptr3);
	// ptr = malloc(16); // -->0x1003807F4
	// memset(ptr, 75, 16);
	// ptr = malloc(16); // -->0x100380824
	// memset(ptr, 75, 16);
	// show_alloc_mem();

	// EMACS
	ptr1 = malloc(8); // --> ptr1
	ptr2 = malloc(16); // --> ptr2
	free(ptr1);
	ptr = malloc(16); // --> 0x100380078
	ptr = malloc(32); // --> 0x1003800A8
	// free(0x100400090);
	// free(0x100400080);
	// free(0x1004000B0);
	ptr = malloc(32); // --> 0x1003800E8
	ptr = malloc(32); // --> 0x100380128
	// free(0x100500240);
	calloc(64, 1); // --> 0x100380168
	calloc(64, 1); // --> 0x1003801C8
	calloc(64, 1); // --> 0x100380228
	calloc(64, 1); // --> 0x100380288
	calloc(64, 1); // --> 0x1003802E8
	ptr = malloc(32); // --> 0x100380348
	// free(0x100500470);
	// free(0x100400100);
	// free(0x100500490);
	calloc(64, 1); // --> 0x100380388
	calloc(64, 1); // --> 0x1003803E8
	calloc(64, 1); // --> 0x100380448
	calloc(64, 1); // --> 0x1003804A8
	calloc(64, 1); // --> 0x100380508
	calloc(64, 1); // --> 0x100380568
	calloc(64, 1); // --> 0x1003805C8
	calloc(64, 1); // --> 0x100380628
	calloc(64, 1); // --> 0x100380688
	calloc(64, 1); // --> 0x1003806E8
	calloc(64, 1); // --> 0x100380748
	calloc(64, 1); // --> 0x1003807A8
	calloc(64, 1); // --> 0x100380808
	calloc(64, 1); // --> 0x100380868
	calloc(64, 1); // --> 0x1003808C8
	// free(0x1005006F0);
	calloc(64, 1); // --> 0x100380928
	calloc(64, 1); // --> 0x100380988
	calloc(64, 1); // --> 0x1003809E8
	calloc(64, 1); // --> 0x100380A48
	calloc(64, 1); // --> 0x100380AA8
	calloc(64, 1); // --> 0x100380B08
	calloc(64, 1); // --> 0x100380B68
	calloc(64, 1); // --> 0x100380BC8
	calloc(64, 1); // --> 0x100380C28
	calloc(64, 1); // --> 0x100380C88
	// free(0x1005007D0);
	calloc(64, 1); // --> 0x100380CE8
	calloc(64, 1); // --> 0x100380D48
	// free(0x100500730);
	// free(0x100500790);
	// free(0x100400160);
	// free(0x100400180);
	// free(0x100500750);
	// free(0x100500020);
	// free(0x1004001A0);
	calloc(64, 1); // --> 0x100380DA8
	calloc(64, 1); // --> 0x100380E08
	// free(0x100500770);
	// free(0x1004003D0);
	// free(0x1005007B0);
	// free(0x100500710);
	// free(0x100500130);
	// free(0x1004003F0);
	calloc(64, 1); // --> 0x100380E68
	calloc(64, 1); // --> 0x100380EC8
	calloc(64, 1); // --> 0x100380F28
	calloc(64, 1); // --> 0x100380F88
	calloc(64, 1); // --> 0x100380FE8
	calloc(64, 1); // --> 0x100381048
	// free(0x100400600);
	calloc(64, 1); // --> 0x1003810A8
	calloc(64, 1); // --> 0x100381108
	calloc(64, 1); // --> 0x100381168
	calloc(64, 1); // --> 0x1003811C8
	// free(0x1004006C0);
	calloc(64, 1); // --> 0x100381228
	calloc(64, 1); // --> 0x100381288
	calloc(64, 1); // --> 0x1003812E8
	calloc(64, 1); // --> 0x100381348
	calloc(64, 1); // --> 0x1003813A8
	calloc(64, 1); // --> 0x100381408
	calloc(64, 1); // --> 0x100381468
	calloc(64, 1); // --> 0x1003814C8
	// free(0x100400620);
	calloc(64, 1); // --> 0x100381528
	calloc(64, 1); // --> 0x100381588
	calloc(64, 1); // --> 0x1003815E8
	calloc(64, 1); // --> 0x100381648
	calloc(64, 1); // --> 0x1003816A8
	calloc(64, 1); // --> 0x100381708
	calloc(64, 1); // --> 0x100381768
	calloc(64, 1); // --> 0x1003817C8
	calloc(64, 1); // --> 0x100381828
	calloc(64, 1); // --> 0x100381888
	calloc(64, 1); // --> 0x1003818E8
	calloc(64, 1); // --> 0x100381948
	// free(0x100400C90);
	// free(0x100400C70);
	// free(0x100400680);
	// free(0x100400800);
	// free(0x1004003B0);
	// free(0x100400780);
	// free(0x100400640);
	// free(0x100400840);
	// free(0x100400700);
	// free(0x1004007C0);
	// free(0x1004001C0);
	// free(0x100400860);
	calloc(64, 1); // --> 0x1003819A8
	calloc(64, 1); // --> 0x100381A08
	// free(0x100401160);
	// free(0x1004011C0);
	// free(0x1004007A0);
	// free(0x1004006A0);
	// free(0x100400660);
	// free(0x100400740);
	// free(0x100400720);
	// free(0x1004007E0);
	// free(0x100400D30);
	// free(0x100400760);
	// free(0x100400820);
	// free(0x1004006E0);
	// free(0x100400410);
	// free(0x100400D50);
	// free(0x100400CF0);
	calloc(64, 1); // --> 0x100381A68
	calloc(64, 1); // --> 0x100381AC8
	calloc(64, 1); // --> 0x100381B28
	calloc(64, 1); // --> 0x100381B88
	calloc(64, 1); // --> 0x100381BE8
	calloc(64, 1); // --> 0x100381C48
	// free(0x1004011E0);
	calloc(64, 1); // --> 0x100381CA8
	calloc(64, 1); // --> 0x100381D08
	// free(0x100401290);
	// free(0x1004012B0);
	calloc(64, 1); // --> 0x100381D68
	calloc(64, 1); // --> 0x100381DC8
	calloc(64, 1); // --> 0x100381E28
	calloc(64, 1); // --> 0x100381E88
	calloc(64, 1); // --> 0x100381EE8
	calloc(64, 1); // --> 0x100381F48
	calloc(64, 1); // --> 0x100381FA8
	calloc(64, 1); // --> 0x100382008
	// free(0x1004012D0);
	// free(0x100401390);
	calloc(64, 1); // --> 0x100382068
	calloc(64, 1); // --> 0x1003820C8
	// free(0x1004012F0);
	// free(0x100401310);
	calloc(64, 1); // --> 0x100382128
	calloc(64, 1); // --> 0x100382188
	// free(0x100401330);
	// free(0x100401350);
	calloc(64, 1); // --> 0x1003821E8
	calloc(64, 1); // --> 0x100382248
	// free(0x100401420);
	calloc(64, 1); // --> 0x1003822A8
	calloc(64, 1); // --> 0x100382308
	calloc(64, 1); // --> 0x100382368
	calloc(64, 1); // --> 0x1003823C8
	calloc(64, 1); // --> 0x100382428
	calloc(64, 1); // --> 0x100382488
	// free(0x100401370);
	// free(0x100400CB0);
	calloc(64, 1); // --> 0x1003824E8
	calloc(64, 1); // --> 0x100382548
	calloc(64, 1); // --> 0x1003825A8
	calloc(64, 1); // --> 0x100382608
	ptr = malloc(8); // --> 0x100382668
	calloc(1, 128); // --> 0x100382690
	ptr = malloc(27); // --> 0x100382730
	calloc(1, 56); // --> 0x10038276B
	calloc(64, 1); // --> 0x1003827C3
	calloc(1, 128); // --> 0x100382823
	ptr = malloc(22); // --> 0x1003828C3
	calloc(1, 72); // --> 0x1003828F9
	calloc(1, 208); // --> 0x100382961
	ptr = malloc(14); // --> 0x100382A51
	calloc(1, 56); // --> 0x100382A7F
	ptr = malloc(45); // --> 0x100382AD7
	ptr = malloc(68); // --> 0x100382B24
	calloc(1, 56); // --> 0x100382B88
	ptr = malloc(45); // --> 0x100382BE0
	ptr = malloc(50); // --> 0x100382C2D
	calloc(1, 56); // --> 0x100382C7F
	ptr = malloc(47); // --> 0x100382CD7
	ptr = malloc(14); // --> 0x100382D26
	calloc(1, 56); // --> 0x100382D54
	ptr = malloc(64); // --> 0x100382DAC
	ptr = malloc(49); // --> 0x100382E0C
	calloc(1, 56); // --> 0x100382E5D
	ptr = malloc(67); // --> 0x100382EB5
	ptr = malloc(52); // --> 0x100382F18
	calloc(1, 56); // --> 0x100382F6C
	ptr = malloc(54); // --> 0x100382FC4
	ptr = malloc(32); // --> 0x10038301A
	free(ptr2);
	calloc(1, 208); // --> 0x10038305A
	calloc(1, 48); // --> 0x10038314A
	ptr = malloc(94); // --> 0x10038319A
	ptr = malloc(16); // --> 0x100383218
	ptr = malloc(64); // --> 0x100383248
	ptr = malloc(14); // --> 0x1003832A8
	calloc(1, 64); // --> 0x1003832D6
	calloc(1, 256); // --> 0x100686020
	ptr4 = realloc(0x0, 256); // --> ptr4
	free(ptr4);
	ptr = malloc(16); // --> 0x100383336
	ptr = malloc(16); // --> 0x100383366
	// show_alloc_mem();

	// ft_putstr("\nSearching size optimisation:\n");
	// for (int i = 1; i < 30; i++) {
	// 	ft_putchar('\n');
	// 	print_debug_size_t((size_t)i, "i");
	// 	print_debug_size_t((i * getpagesize() - 3200) / 100	, "space left");
	// }

	return (0);
}
