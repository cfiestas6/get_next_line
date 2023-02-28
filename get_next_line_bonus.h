#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_joinstr(char const *s1, char const *s2);
char *get_next_line(int fd);
