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
	char *buffer; // return value [BUFFER_SIZE + 1]
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	if (!read(fd, buffer, BUFFER_SIZE))

}

// int main()
// {
// 	printf("%d", ft_line_end("hola que tal es\ntas"));
// 	return (0);
// }
