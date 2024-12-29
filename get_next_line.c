/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:06:32 by ccalabro          #+#    #+#             */
/*   Updated: 2024/09/30 19:13:04 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int			i;
	int			r_read;

	i = 0;
	line = NULL;
	r_read = 1;
	while (ft_strchr(line, '\n') == 0)
	{
		if (!*buff)
			r_read = read(fd, buff, BUFFER_SIZE);
		if (r_read <= 0)
			break ;
		i++;
		line = ft_realloc(line, i);
		ft_strlcat_plus(line, buff);
	}
	if (line && *line)
		return (line);
	else
		free(line);
	return (NULL);
}
