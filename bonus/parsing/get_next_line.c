/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:21:50 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/03 00:30:51 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dialy(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (ft_strlen(str) == 0)
		return (0);
	return (ft_substr(str, 0, i + 1));
}

char	*afterline(char *str, char v)
{
	int		i;
	char	*salma;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == v)
		{
			salma = ft_substr(str, i + 1, ft_strlen(str));
			free (str);
			return (salma);
		}	
		i++;
	}
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	char		*buf;
	int			i;

	buf = malloc(sizeof(char) * 2);
	if (!buf)
	{
		free(saved);
		return (NULL);
	}
	i = 1;
	while (ft_strchr(saved) == 0 && i > 0)
	{		
		i = read(fd, buf, 1);
		if (i >= 0)
		{
			buf[i] = '\0';
			saved = ft_strjoin(saved, buf);
		}
	}
	line = dialy(saved, '\n');
	saved = afterline(saved, '\n');
	free(buf);
	return (line);
}
