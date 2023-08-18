/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:47:01 by iergun            #+#    #+#             */
/*   Updated: 2023/03/07 03:47:02 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *str, char *str2)
{
	char	*ret;
	int		sayac;

	sayac = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(str2) + 1));
	if (!ret)
		return (0);
	while (str && *str)
		ret[sayac++] = *str++;
	while (str2 && *str2)
		ret[sayac++] = *str2++;
	ret[sayac] = '\0';
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*start_ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	start_ptr = (char *)s + start;
	i = 0;
	while (i < len && *start_ptr)
	{
		ret[i] = *start_ptr;
		start_ptr++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
		if (*s++ == (char)c)
			return ((char *)s);
	return (NULL);
}
