/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa <jsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:35:08 by jsousa            #+#    #+#             */
/*   Updated: 2021/04/22 20:54:12 by jsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	dest = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str != (unsigned char)c)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return ((char *)str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*memory_dest;
	const unsigned char	*memory_src;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	memory_dest = (unsigned char *)dest;
	memory_src = (unsigned char *)src;
	while (i < n)
	{
		memory_dest[i] = memory_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*result;

	if (!str1 || !str2)
		return (0);
	result = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!result)
		return (0);
	else
	{
		ft_memcpy(result, str1, ft_strlen(str1));
		ft_memcpy(result + ft_strlen(str1), str2, ft_strlen(str2) + 1);
	}
	return (result);
}
