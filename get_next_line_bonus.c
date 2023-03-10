/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:56:16 by cfiestas          #+#    #+#             */
/*   Updated: 2023/02/28 19:59:30 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	ft_strn(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
		if (s[i++] == c)
			return (1);
	return (0);
}

static char	*ft_readandjoin(int fd, char *saved)
{
	ssize_t	size;
	char	*temp;

	temp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	size = 1;
	while (!ft_strn(saved, '\n') && size)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size < 0)
		{
			free(temp);
			return (0);
		}
		temp[size] = '\0';
		saved = ft_joinstr(saved, temp);
	}
	free(temp);
	return (saved);
}

static char	*ft_slice(char *str)
{
	char	*result;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	result = (char *) malloc((i + 2) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

static char	*ft_next_str(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	result = (char *) malloc(ft_strlen(str) - i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (str[++i])
		result[j++] = str[i];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(saved[fd]);
		saved[fd] = NULL;
		return (0);
	}
	saved[fd] = ft_readandjoin(fd, saved[fd]);
	if (!saved[fd])
		return (0);
	buf = ft_slice(saved[fd]);
	saved[fd] = ft_next_str(saved[fd]);
	return (buf);
}
