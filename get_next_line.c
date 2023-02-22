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

char *get_next_line(int fd)
{
	static char *next; // static string next line [OPEN_MAX]
	char *str; // return value [BUFFER_SIZE + 1]
	int size;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	str = (char *) malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);

	// if (!read(fd, str, BUFFER_SIZE))
	// 	return (0);
	
	while(!ft_strn(str))
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size <= 0)
			break ;
		readstr[size] = 0;
		next[fd] = ft_strjoin(next[fd], str)
	}

}

// int main()
// {
// 	printf("%d", ft_line_end("hola que tal es\ntas"));
// 	return (0);
// }
