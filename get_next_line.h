#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_joinstr(char const *s1, char const *s2);
size_t	ft_strlcpy(const char *dst, const char *src, size_t dstsize);
char *get_next_line(int fd);
