#include "ft_malloc.h"

static uint8_t		count_numeral_base16_malloc(uintptr_t nb)
{
	uint8_t		count;

	count = 1;
	while (nb /= 16)
		++count;
	return (count);
}

static void				ft_ptoa_base_malloc(uintptr_t nb, char *output)
{
	size_t		length;
	char		*alph;

	alph = "0123456789ABCDEF";
	length = (size_t)count_numeral_base16_malloc(nb);
	output[length] = '\0';
	while (nb != 0)
	{
		length--;
		output[length] = alph[nb % 16];
		nb /= 16;
	}
	if (length > 0)
	{
		while (--length > 0)
			output[length] = '0';
		output[0] = '0';
	}
}

void	print_addr(void *ptr) {
	uint8_t		length;
	char		*output;
	uintptr_t	uip;

	uip = (uintptr_t)ptr;
	length = count_numeral_base16_malloc(uip) + 1;
	output = (char *)mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_ptoa_base_malloc(uip, output);
	ft_putstr(output);
	munmap(ptr, 0);
}

void		printsize(size_t n)
{
	if (n >= 10)
	{
		printsize(n / 10);
		printsize(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	print_mem(t_block_mem *mem, char *zone)
{
	if (mem != NULL) {
		ft_putstr(zone);
		ft_putstr(" : 0x");
		print_addr((void *)mem);
		ft_putchar('\n');
		while (mem != NULL)
		{
			ft_putstr("0x");
			print_addr((void *)mem + sizeof(t_block_mem) + 1);
			ft_putstr(" - 0x");
			print_addr((void *)mem + sizeof(t_block_mem) + 1 + mem->size);
			ft_putstr(" : ");
			printsize(mem->size);
			ft_putstr(" octets\n");
			mem = mem->next;
		}
	}
	else
	{
		ft_putstr(zone);
		ft_putstr(" : not used\n");
	}
}

void	show_alloc_mem() {
	print_mem(g_mem[0], "TINY");
	print_mem(g_mem[1], "SMALL");
	print_mem(g_mem[2], "LARGE");
}
