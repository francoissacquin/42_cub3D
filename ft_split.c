/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:50:01 by fsacquin          #+#    #+#             */
/*   Updated: 2021/04/18 17:03:31 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	split_size(char const *s, char c)
{
	int		final_size;
	int		j;

	final_size = 0;
	j = 1;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			j = 1;
		else if (j == 1)
		{
			j = 0;
			final_size++;
		}
		s++;
	}
	return (final_size);
}

static int	temp_size(char const *s, char c, int i)
{
	int		temp_len;

	temp_len = 0;
	while (s[i] && s[i] != c)
	{
		temp_len++;
		i++;
	}
	return (temp_len);
}

char	**send_help(char const **split, int abs)
{
	while (abs > 0)
	{
		abs--;
		free((void *)split[abs]);
	}
	free((void *)split);
	return (NULL);
}

static char	**append_sections(char const *s, char **split, char c, int len)
{
	int		i;
	int		abs;
	int		index;

	i = 0;
	abs = 0;
	while (s[i] && abs < len)
	{
		index = 0;
		while (s[i] == c)
			i++;
		split[abs] = (char *)malloc(sizeof(char) * temp_size(s, c, i) + 1);
		if (split[abs] == NULL)
			return (send_help((char const **)split, abs));
		while (s[i] && s[i] != c)
		{
			split[abs][index] = s[i];
			index++;
			i++;
		}
		split[abs][index] = '\0';
		abs++;
	}
	split[abs] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		len;

	if (!s)
		return (NULL);
	len = split_size(s, c);
	split = NULL;
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (split == NULL)
		return (NULL);
	return (append_sections(s, split, c, len));
}
