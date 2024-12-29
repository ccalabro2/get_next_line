/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:38:45 by ccalabro          #+#    #+#             */
/*   Updated: 2024/09/30 19:11:27 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[4096][BUFFER_SIZE + 1];
	int			i;
	int			r_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	i = 0;
	line = NULL;
	r_read = 1;
	while (ft_strchr(line, '\n') == 0)
	{
		if (!*buff[fd])
			r_read = read(fd, buff[fd], BUFFER_SIZE);
		if (r_read <= 0)
			break ;
		i++;
		line = ft_realloc(line, i);
		ft_strlcat_plus(line, buff[fd]);
	}
	if (line && *line)
		return (line);
	else
		free(line);
	return (NULL);
}
