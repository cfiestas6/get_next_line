#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_joinstr(char const *s1, char const *s2);
char *get_next_line(int fd);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
