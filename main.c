#include <stdio.h>
#include <unistd.h>
#include "./get_next_line.h"

int main()
{
	int fd = open("hola.txt");
	get_next_line(fd);
	return (0);
}
