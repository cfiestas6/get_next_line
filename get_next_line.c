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

int ft_strn(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n' || s[i] == '\0')
			return (1);
	return (0);
}

char *ft_readandjoin() // returns result of joining existing result with buf when does not include '\n'
{

}

char *get_next_line(int fd)
{
	static char *saved; // static string next line [OPEN_MAX]
	char *buf; // return value [BUFFER_SIZE + 1]
 	char *result;
 	int size;
 	
 	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
 		return (0);
 	buf = (char *) malloc(BUFFER_SIZE + 1);
 	if (!buf)
 		return (0);

 	// if (!read(fd, str, BUFFER_SIZE))
 	// 	return (0);
 	
 	// 1 comprobar si saved tiene '\n'
 	//	false: 
 	//		read(fd, str, BUFFER_SIZE)
 	//		join(saved, str)
 	//		volver al paso 1
 	//
 	//	true:
 	//		result = until '\n'
 	//		saved = after '\n'

 	while(!ft_strn(result))
 	{
 		if (read(fd, buf, BUFFER_SIZE) <= 0) // el archivo ha terminado
 			break ;
 		buf[size] = 0;
 		result = ft_joinstr(result, str);
 		if (!result)
 		{
 			free(result);
 			return (0);
		}
	}

}

int main()
{
	printf("%s", ft_joinstr("hola", " que tal"));
	return (0);
}

