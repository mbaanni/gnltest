/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:55:03 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/07 18:48:35 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*ptr;
	char		*line;
	char		*lineo;
	int			i;

	ptr = 0;
	lineo = 0;
	if (buf[0] != 0)
	{
		lineo = join_rest(lineo, buf);
		to_keep(lineo, buf);
		i = 0;
		while (lineo[i])
		{
			if(lineo[i] == '\n')
			{
				lineo[i + 1] = 0;
				return(lineo);
			}
			i++;
		}
	}
	i = 0;
	line = read_line(fd, lineo);
	if (line == 0)
		return (0);
	if (*line == 0)
		return (0);
	to_keep(line, buf);
	while (line[i])
	{
		if (line[i] == '\n')
			if (line[i + 1])
				line[i + 1] = 0;
		i++;
	}
	return (line);
}
char	*read_line(int fd, char *lineo)
{
	char	str[BUFFER_SIZE + 1];
	int		i;
	i = 1;
	*str = 0;
	while (i && ft_strchr(str))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
			return (0);
		str[i] = 0;
		lineo = ft_strjoin(lineo, str);
	}
	return (lineo);
}

void	to_keep(char *line, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(line);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (i == j)
	{
		*buf = 0;
		return ;
	}
	j = 0;
	while (line[i])
		buf[j++] = line[i++];
	buf[j] = 0;
}
