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
#include <sys/_types/_ssize_t.h>


static int ft_strn(char *s)
{
	int i;

	i = -1;
	while (s[++i] && s)
		if (s[i] == '\n' || s[i] == '\0')
			return (1);
	return (0);
}

static char *ft_readandjoin(int fd, char *result) // returns result of joining existing result with buf when does not include '\n'
{
	ssize_t size;
	char *temp;

	temp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!temp)
	{
		free(temp);
		return (0);
	}
	size = 1;
	while(size)
 	{
		
		size = read(fd, temp, BUFFER_SIZE);
 		if (size <= 0) // el archivo ha terminado
		{
			free(temp);
			return (0);
		}
		temp[size] = 0;
                result = ft_joinstr(result, temp);
 		if (!result)
 		{
			printf("result da error");
			free(temp);
 			return (0);
		}
		if (ft_strn(temp))
			break ;
	}
	free(temp);
	return (result);
}
/*
static char *ft_slice(char *str)
{
	char *result;
	int i;

	result = (char *) malloc(ft_strlen(str) + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i]= str[i];
                i++;
	}
	if (str[i] == '\n')
		result[i] = '\n';
	return (result);
}

static char *ft_next_str(char *str)
{
	char *result;
	int i;
	size_t size;

	i = -1;
	result = 0;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1])
		{
			size = ft_strlen(str) - i;
			result = (char *) malloc(size);
	                if (!result)
				return (0);
			ft_strlcpy(result, (str + i + 1), size); // que empiece a copiar desde el salto de linea
		}
	}
	free(str);
	return (result);
}*/

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
	static char *saved; // static string next line [OPEN_MAX]
	// char *buf; // return value [BUFFER_SIZE + 1]
 	
 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(saved);
		saved = NULL;
		return (0);
	}
	saved = ft_readandjoin(fd, saved);
	if (!saved)
		return (0);
	printf("%s", saved);
	//buf = ft_slice(saved);
	//saved = ft_next_str(saved);
	return (0);
}

int main()
{
	int fd = open("hola.txt", O_RDONLY);

	get_next_line(fd);

	// printf("%s", ft_readandjoin(fd));
	return (0);
}
