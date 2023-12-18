/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:38:00 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:21:39 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*result;
	size_t	count;

	if (size != 0 && n > SIZE_MAX / size)
		return (NULL);
	result = (void *)malloc(n * size);
	if (!result)
		return (NULL);
	count = 0;
	while (count < n * size)
	{
		*(char *)(result + count) = 0;
		count++;
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dest && !size)
		return (src_len);
	dest_len = ft_strlen(dest);
	i = 0;
	if (dest_len < size -1 && size > 0)
	{
		while (i < size - dest_len - 1 && src[i])
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[i + dest_len] = '\0';
	}
	if (size <= dest_len)
		return (size + src_len);
	return (src_len + dest_len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	if (!s)
		return (NULL);
	while (c >= 256)
		c -= 256;
	while (c < 0)
		c += 256;
	result = (char *)s;
	while (*result != '\0')
	{
		if (*result == (char)c)
			return (result);
		result++;
	}
	if (c == '\0')
		return (result);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	count;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	count = -1;
	if (s1)
		while (s1[++count] != '\0')
			result[count] = s1[count];
	result[count] = '\0';
	ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (result);
}
