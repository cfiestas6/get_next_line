#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	while (str[n++]);
	return (n - 1);
}

char	*ft_joinstr(char *s1, char *s2)
{
	int i;
	int j;
	char *result;

	if (!s1 || !s2)
		return (0);
	result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	j = 0;
	i = -1;
	printf("len de s1: %d\n", ft_strlen(s1));
	printf("len de s2: %d\n", ft_strlen(s2));
	while (++i < ft_strlen(s1))
		result[i] = s1[i];
	while (j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[i + j] = 0;
	return (result);
}
