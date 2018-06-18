#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			main(int ac, char **av)
{
	void	*ptr;

	ptr = malloc(1);
	if (ptr == NULL) {
		write(1, "Malloc = NULL\n", 14);
	}
	else {
		write(1, "Malloc > 0\n", 11);
	}
	// printf("getpagesize = %d\n", getpagesize());
	// int		i;
	// int		nb;
	// char	c;
	// char	*str;
    //
	// (void)ac;
	// (void)av;
	// nb = 42;
	// c = 'Q';
	// str = (char *)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// i = 0;
	// while (i < nb)
	// {
	// 	str[i] = c;
	// 	i++;
	// }
	// str[i] = '\0';
	// printf("%s\n", str);
	return (0);
}
