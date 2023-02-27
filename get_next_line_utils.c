#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(char const *str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n++]);
	return (n - 1);
}

char	*ft_joinstr(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *result;

	if (!s2)
		return (0);
	result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	j = 0;
	i = -1;
	while (++i < ft_strlen(s1))
		result[i] = s1[i];
	while (j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[i] = 0;
	return (result);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	while (dstsize != 0 && i < srcsize && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
