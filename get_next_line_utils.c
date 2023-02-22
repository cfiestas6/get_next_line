#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n++]);
	return (n);
}

static size_t	ft_getindex(size_t s1_len, char *r, char const *s1)
{
	size_t	i;

	i = -1;
	while (++i < s1_len)
		r[i] = s1[i];
	return (i);
}

static char *ft_freestr(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (0);
}

char	*ft_joinfree(char *s1, char *s2)
{
	int i;
	int j;
	char *result;

	if (!s1 || !s2)
		return (ft_freestr(s1, s2));
	result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (ft_freestr(s1, s2));
	j = 0;
	// i = ft_getindex(ft_strlen(s1), result, s1);
	i = -1;
	while (++i < ft_strlen(s1))
		r[i] = s1[i];
	while (j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[i] = 0;
	ft_freestr(s1, s2);
	return (result);
}
