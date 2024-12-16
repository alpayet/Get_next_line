/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:26:19 by alpayet           #+#    #+#             */
/*   Updated: 2024/12/16 22:17:15 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	cs = (unsigned char *)s;
	i = -1;
	while (++i < n)
		cs[i] = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((SIZE_MAX / nmemb) < size)
		return (NULL);
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_memset(s, '\0', nmemb * size);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	dest_char = dest;
	src_char = src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size != 0)
	{
		while (src[++i] && i < size - 1)
			dest[i] = src[i];
		dest[i] = '\0';
		while (++i < size - 1)
			dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	sub_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	sub = ft_calloc((sub_len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < sub_len)
		sub[i] = s[start + i];
	return (sub);
}

char	*ft_strjoin_alt(char *s1, char *s2)
{
	char	*s;
	size_t	total_len;

	if (s1 == NULL)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (s1 == NULL)
			return (NULL);
	}
	total_len = ft_strlen(s1) + ft_strlen(s2);
	s = ft_calloc(total_len + 1, sizeof(char));
	if (!s)
	{
		
		free(s1);
		return (NULL);
	}
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s + ft_strlen(s), s2, ft_strlen(s2) + 1);
	free(s1);
	return (s);
}


/* int	main(void)
{
	char a[]="fdv\n";

	printf("a:%s\n", a);
	ft_strlcpy(a, ft_strchr(a, '\n') + 1, ft_strlen(ft_strchr(a, '\n') + 1)
		+ 1);
	printf("a:%s\n", a);
} */
