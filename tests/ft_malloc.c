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

	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;
	char	*str8;
	char	*str9;
	char	*str10;
	char	*str11;
	char	*str12;
	char	*str13;
	char	*str14;
	char	*str15;
	char	*str16;

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

	ptr1 = malloc(259);
	ptr1 = malloc(19);
	ptr2 = malloc(19);
	str1 = (char*)malloc(19);
	strcpy(str1, "abcdefghijklmnopqrstuvxyzABCDEF");
	str1[1] = (char)11;
	show_alloc_mem_ex(str1);
	ft_putstr("+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	ptr = calloc(48, 1);
	ptr = realloc(ptr, 32);
	ptr = reallocf(ptr, 48);
	ptr = reallocf(ptr, 64);
	free(ptr);
	show_alloc_history();
	// // EMACS
	// ptr1 = malloc(8); // --> ptr1
	// ptr2 = malloc(16); // --> ptr2
	// free(ptr1);
	// ptr = malloc(16); // --> 0x100380078
	// ptr = malloc(32); // --> 0x1003800A8
	// // free(0x100400090);
	// // free(0x100400080);
	// // free(0x1004000B0);
	// ptr = malloc(32); // --> 0x1003800E8
	// ptr = malloc(32); // --> 0x100380128
	// // free(0x100500240);
	// calloc(64, 1); // --> 0x100380168
	// calloc(64, 1); // --> 0x1003801C8
	// calloc(64, 1); // --> 0x100380228
	// calloc(64, 1); // --> 0x100380288
	// calloc(64, 1); // --> 0x1003802E8
	// ptr = malloc(32); // --> 0x100380348
	// // free(0x100500470);
	// // free(0x100400100);
	// // free(0x100500490);
	// calloc(64, 1); // --> 0x100380388
	// calloc(64, 1); // --> 0x1003803E8
	// calloc(64, 1); // --> 0x100380448
	// calloc(64, 1); // --> 0x1003804A8
	// calloc(64, 1); // --> 0x100380508
	// calloc(64, 1); // --> 0x100380568
	// calloc(64, 1); // --> 0x1003805C8
	// calloc(64, 1); // --> 0x100380628
	// calloc(64, 1); // --> 0x100380688
	// calloc(64, 1); // --> 0x1003806E8
	// calloc(64, 1); // --> 0x100380748
	// calloc(64, 1); // --> 0x1003807A8
	// calloc(64, 1); // --> 0x100380808
	// calloc(64, 1); // --> 0x100380868
	// calloc(64, 1); // --> 0x1003808C8
	// // free(0x1005006F0);
	// calloc(64, 1); // --> 0x100380928
	// calloc(64, 1); // --> 0x100380988
	// calloc(64, 1); // --> 0x1003809E8
	// calloc(64, 1); // --> 0x100380A48
	// calloc(64, 1); // --> 0x100380AA8
	// calloc(64, 1); // --> 0x100380B08
	// calloc(64, 1); // --> 0x100380B68
	// calloc(64, 1); // --> 0x100380BC8
	// calloc(64, 1); // --> 0x100380C28
	// calloc(64, 1); // --> 0x100380C88
	// // free(0x1005007D0);
	// calloc(64, 1); // --> 0x100380CE8
	// calloc(64, 1); // --> 0x100380D48
	// // free(0x100500730);
	// // free(0x100500790);
	// // free(0x100400160);
	// // free(0x100400180);
	// // free(0x100500750);
	// // free(0x100500020);
	// // free(0x1004001A0);
	// calloc(64, 1); // --> 0x100380DA8
	// calloc(64, 1); // --> 0x100380E08
	// // free(0x100500770);
	// // free(0x1004003D0);
	// // free(0x1005007B0);
	// // free(0x100500710);
	// // free(0x100500130);
	// // free(0x1004003F0);
	// calloc(64, 1); // --> 0x100380E68
	// calloc(64, 1); // --> 0x100380EC8
	// calloc(64, 1); // --> 0x100380F28
	// calloc(64, 1); // --> 0x100380F88
	// calloc(64, 1); // --> 0x100380FE8
	// calloc(64, 1); // --> 0x100381048
	// // free(0x100400600);
	// calloc(64, 1); // --> 0x1003810A8
	// calloc(64, 1); // --> 0x100381108
	// calloc(64, 1); // --> 0x100381168
	// calloc(64, 1); // --> 0x1003811C8
	// // free(0x1004006C0);
	// calloc(64, 1); // --> 0x100381228
	// calloc(64, 1); // --> 0x100381288
	// calloc(64, 1); // --> 0x1003812E8
	// calloc(64, 1); // --> 0x100381348
	// calloc(64, 1); // --> 0x1003813A8
	// calloc(64, 1); // --> 0x100381408
	// calloc(64, 1); // --> 0x100381468
	// calloc(64, 1); // --> 0x1003814C8
	// // free(0x100400620);
	// calloc(64, 1); // --> 0x100381528
	// calloc(64, 1); // --> 0x100381588
	// calloc(64, 1); // --> 0x1003815E8
	// calloc(64, 1); // --> 0x100381648
	// calloc(64, 1); // --> 0x1003816A8
	// calloc(64, 1); // --> 0x100381708
	// calloc(64, 1); // --> 0x100381768
	// calloc(64, 1); // --> 0x1003817C8
	// calloc(64, 1); // --> 0x100381828
	// calloc(64, 1); // --> 0x100381888
	// calloc(64, 1); // --> 0x1003818E8
	// calloc(64, 1); // --> 0x100381948
	// // free(0x100400C90);
	// // free(0x100400C70);
	// // free(0x100400680);
	// // free(0x100400800);
	// // free(0x1004003B0);
	// // free(0x100400780);
	// // free(0x100400640);
	// // free(0x100400840);
	// // free(0x100400700);
	// // free(0x1004007C0);
	// // free(0x1004001C0);
	// // free(0x100400860);
	// calloc(64, 1); // --> 0x1003819A8
	// calloc(64, 1); // --> 0x100381A08
	// // free(0x100401160);
	// // free(0x1004011C0);
	// // free(0x1004007A0);
	// // free(0x1004006A0);
	// // free(0x100400660);
	// // free(0x100400740);
	// // free(0x100400720);
	// // free(0x1004007E0);
	// // free(0x100400D30);
	// // free(0x100400760);
	// // free(0x100400820);
	// // free(0x1004006E0);
	// // free(0x100400410);
	// // free(0x100400D50);
	// // free(0x100400CF0);
	// calloc(64, 1); // --> 0x100381A68
	// calloc(64, 1); // --> 0x100381AC8
	// calloc(64, 1); // --> 0x100381B28
	// calloc(64, 1); // --> 0x100381B88
	// calloc(64, 1); // --> 0x100381BE8
	// calloc(64, 1); // --> 0x100381C48
	// // free(0x1004011E0);
	// calloc(64, 1); // --> 0x100381CA8
	// calloc(64, 1); // --> 0x100381D08
	// // free(0x100401290);
	// // free(0x1004012B0);
	// calloc(64, 1); // --> 0x100381D68
	// calloc(64, 1); // --> 0x100381DC8
	// calloc(64, 1); // --> 0x100381E28
	// calloc(64, 1); // --> 0x100381E88
	// calloc(64, 1); // --> 0x100381EE8
	// calloc(64, 1); // --> 0x100381F48
	// calloc(64, 1); // --> 0x100381FA8
	// calloc(64, 1); // --> 0x100382008
	// // free(0x1004012D0);
	// // free(0x100401390);
	// calloc(64, 1); // --> 0x100382068
	// calloc(64, 1); // --> 0x1003820C8
	// // free(0x1004012F0);
	// // free(0x100401310);
	// calloc(64, 1); // --> 0x100382128
	// calloc(64, 1); // --> 0x100382188
	// // free(0x100401330);
	// // free(0x100401350);
	// calloc(64, 1); // --> 0x1003821E8
	// calloc(64, 1); // --> 0x100382248
	// // free(0x100401420);
	// calloc(64, 1); // --> 0x1003822A8
	// calloc(64, 1); // --> 0x100382308
	// calloc(64, 1); // --> 0x100382368
	// calloc(64, 1); // --> 0x1003823C8
	// calloc(64, 1); // --> 0x100382428
	// calloc(64, 1); // --> 0x100382488
	// // free(0x100401370);
	// // free(0x100400CB0);
	// calloc(64, 1); // --> 0x1003824E8
	// calloc(64, 1); // --> 0x100382548
	// calloc(64, 1); // --> 0x1003825A8
	// calloc(64, 1); // --> 0x100382608
	// ptr = malloc(8); // --> 0x100382668
	// calloc(1, 128); // --> 0x100382690
	// ptr = malloc(27); // --> 0x100382730
	// calloc(1, 56); // --> 0x10038276B
	// calloc(64, 1); // --> 0x1003827C3
	// calloc(1, 128); // --> 0x100382823
	// ptr = malloc(22); // --> 0x1003828C3
	// calloc(1, 72); // --> 0x1003828F9
	// calloc(1, 208); // --> 0x100382961
	// ptr = malloc(14); // --> 0x100382A51
	// calloc(1, 56); // --> 0x100382A7F
	// ptr = malloc(45); // --> 0x100382AD7
	// ptr = malloc(68); // --> 0x100382B24
	// calloc(1, 56); // --> 0x100382B88
	// ptr = malloc(45); // --> 0x100382BE0
	// ptr = malloc(50); // --> 0x100382C2D
	// calloc(1, 56); // --> 0x100382C7F
	// ptr = malloc(47); // --> 0x100382CD7
	// ptr = malloc(14); // --> 0x100382D26
	// calloc(1, 56); // --> 0x100382D54
	// ptr = malloc(64); // --> 0x100382DAC
	// ptr = malloc(49); // --> 0x100382E0C
	// calloc(1, 56); // --> 0x100382E5D
	// ptr = malloc(67); // --> 0x100382EB5
	// ptr = malloc(52); // --> 0x100382F18
	// calloc(1, 56); // --> 0x100382F6C
	// ptr = malloc(54); // --> 0x100382FC4
	// ptr = malloc(32); // --> 0x10038301A
	// free(ptr2);
	// calloc(1, 208); // --> 0x10038305A
	// calloc(1, 48); // --> 0x10038314A
	// ptr = malloc(94); // --> 0x10038319A
	// ptr = malloc(16); // --> 0x100383218
	// ptr = malloc(64); // --> 0x100383248
	// ptr = malloc(14); // --> 0x1003832A8
	// calloc(1, 64); // --> 0x1003832D6
	// calloc(1, 256); // --> 0x100686020
	// ptr4 = realloc(0x0, 256); // --> ptr4
	// free(ptr4);
	// ptr = malloc(16); // --> 0x100383336
	// ptr = malloc(16); // --> 0x100383366
	// // show_alloc_mem();

	// ft_putstr("\nSearching size optimisation:\n");
	// for (int i = 1; i < 30; i++) {
	// 	ft_putchar('\n');
	// 	print_debug_size_t((size_t)i, "i");
	// 	print_debug_size_t((i * getpagesize() - 3200) / 100	, "space left");
	// }

	return (0);
}
