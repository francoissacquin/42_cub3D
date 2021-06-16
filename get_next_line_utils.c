/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:27:03 by fsacquin          #+#    #+#             */
/*   Updated: 2020/11/13 16:05:17 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_strlen(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	int				i;
	char			*ptr;

	i = 0;
	while (str[i])
		i++;
	ptr = 0;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	int				i;
	int				j;
	int				len;
	char			*ptr;

	if (!str1)
		return ((char *)str2);
	if (!str2)
		return ((char *)str1);
	len = ft_strlen(str1) + ft_strlen(str2);
	ptr = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++i])
		ptr[i] = str1[i];
	while (str2[++j])
		ptr[i + j] = str2[j];
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	char			*ptr;

	i = 0;
	ptr = (char *)str;
	while (str[i])
	{
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	i--;
	ptr = ptr + i;
	while (i >= 0)
	{
		if (str[i] == c)
		{
			return (ptr);
		}
		ptr--;
		i--;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	while (s[start + i] && i < len)
		i++;
	ptr = 0;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
