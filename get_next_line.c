#include "./get_next_line.h"
#include <limits.h>
#include <stdio.h>

#define BUFFER_SIZE 5

int ft_strn(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char *get_next_line(int fd)
{
	static char *next[OPEN_MAX]
	char buffer[BUFFER_SIZE + 1];
}

// int main()
// {
// 	printf("%d", ft_line_end("hola que tal es\ntas"));
// 	return (0);
// }
