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

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	j = 0;
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}
