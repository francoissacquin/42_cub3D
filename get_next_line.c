/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:00:03 by fsacquin          #+#    #+#             */
/*   Updated: 2020/11/15 17:11:36 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*read_line(char *str, int fd, int *read_len)
{
	char			buffer[10 + 1];
	char			*temp;

	*read_len = read(fd, buffer, 10);
	while ((*read_len) > 0)
	{
		buffer[*read_len] = '\0';
		if (str == NULL)
			str = ft_strdup(buffer);
		else
		{
			temp = str;
			str = ft_strjoin(str, buffer);
			free(temp);
		}
		if (ft_strrchr(str, '\n'))
			break ;
		*read_len = read(fd, buffer, 10);
	}
	return (str);
}

char	*chad_buffer(char *str)
{
	int				len;
	unsigned int	i;
	char			*temp;

	len = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		temp = str;
		str = ft_substr(str, i + 1, len - i - 1);
		free(temp);
		temp = 0;
	}
	return (str);
}

int	finish_line(char *str, char **line)
{
	int				i;

	i = 0;
	if (str == NULL)
	{
		*line = ft_strdup("");
		return (-1);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_substr(str, 0, i);
		return (1);
	}
	else
	{
		*line = ft_strdup(str);
		return (-1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char		*str[256];
	int				read_len;
	int				over_buffer_switch;

	if (line == NULL || read(fd, str[fd], 0))
		return (-1);
	str[fd] = read_line(str[fd], fd, &read_len);
	if (read_len < 0)
		return (-1);
	over_buffer_switch = finish_line(str[fd], line);
	if (over_buffer_switch == 1)
		str[fd] = chad_buffer(str[fd]);
	else
	{
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}
