/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiestas <cfiestas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:06:00 by cfiestas          #+#    #+#             */
/*   Updated: 2023/02/20 11:06:03 by cfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int ft_strn(char *s)
{
	int i;

	i = -1;
	while (s[++i] && s)
		if (s[i] == '\n' || s[i] == '\0')
			return (1);
	return (0);
}

static char *ft_readandjoin(int fd)
{
	ssize_t size;
	char *temp;
	char *result;

	temp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!temp)
		return (0);
	size = 1;
	while(size)
 	{
		size = read(fd, temp, BUFFER_SIZE);
 		if (size <= 0)
		        break ;
		temp[size] = 0;
                result = ft_joinstr(result, temp);
 		if (!result || ft_strn(temp))
			break ;
	}
	if (temp)
		free(temp);
	// printf("readandjoin = %s", result);
	return (result);
}

static char *ft_slice(char *str)
{
	char *result;
	int i;
	int j;

	if (!str)
		return (0);
	j = 0;
	while (str[j++] != '\n');
	result = (char *) malloc(j + 1);
	if (!result)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i]= str[i];
                i++;
	}
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = 0;
	// printf("\nslice = %s\n", result);
	return (result);
}

static char *ft_next_str(char *str)
{
	char	*result;
	int		i;
	size_t	size;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
		{
			size = ft_strlen(str) - i;
			result = (char *) malloc(size);
	                if (!result)
			{
				free(str);
				return (0);
			}
			ft_strlcpy(result, &str[i + 1], size);
		}
	}
	if (str)
		free(str);
	// printf("next str = %s\n", result);
	return (result);
}

// 1 comprobar si saved tiene '\n'
//	false: 
//		read(fd, str, BUFFER_SIZE) --> readandjoin
//		join(saved, str)
//		volver al paso 1
//
//	true:
//		guardar en una temporal hasta el '\n' incluido 
//		result = join temp con result
//		saved = after '\n'

char *get_next_line(int fd)
{
	static char	*saved;
	char		*buf;

 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(saved);
		saved = NULL;
		return (0);
	}
	saved = ft_readandjoin(fd);
	if (!saved)
		return (0);
	buf = ft_slice(saved);
	saved = ft_next_str(saved);
	return (buf);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	// char *stash = get_next_line(fd);

	/*
	while (stash)
	{
		printf("%s", stash);
		stash = get_next_line(fd);
	}
	free(stash);*/
	return (0);
}
