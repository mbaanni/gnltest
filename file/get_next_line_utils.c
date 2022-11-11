/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:56:23 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/07 18:41:43 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(int i, int size)
{
	char	*ptr;

	ptr = malloc(size * i);
	if (!ptr)
		return (0);
	*ptr = 0;
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *ptr, char *str)
{
	char	*newline;
	int		i;
	int		j;

	i = 0;
	if (!ptr)
		ptr = ft_calloc(1, sizeof(char));
	if (!ptr)
		return (0);
	newline = malloc(sizeof(char) * (ft_strlen(ptr) + ft_strlen(str) + 1));
	if (!newline)
		return (0);
	while (ptr[i])
	{
		newline[i] = ptr[i];
		i++;
	}
	j = 0;
	while (str[j])
		newline[i++] = str[j++];
	newline[i] = 0;
	free(ptr);
	return (newline);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
char	*join_rest(char *line, char *buf)
{
	int	i;
	int	j;

	i = 0;
	while(buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i);
	if (!line)
		return (0);
	j = 0;
	while(buf[j] && buf[j] != '\n')
	{
		line[j] = buf[j];
		buf[j++] = buf[i++];
	}
	if(buf[j] == '\n')
	{
		line[j] = '\n';
		i++;
	}
	line[++j] = 0;
	while(buf[j])
		buf[j++] = buf[i++];
	buf[j] = 0;
	return (line);
}
