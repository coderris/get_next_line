/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:50:44 by lanton-m          #+#    #+#             */
/*   Updated: 2025/05/02 21:59:50 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (*c)
	{
		i += 1;
		c++;
	}
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	char	c_c;
	int		i;

	c_c = (char)c;
	i = 0;
	if (!s && c_c != '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == c_c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c_c)
		return ((char *)s + i);
	return (NULL);
}
char	*ft_strdup(const char *s1)
{
	char	*aux;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (len > 16711568)
		return (NULL);
	aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	i = 0;
	while (i < len)
	{
		aux[i] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

static char	*new_str(char const *s, size_t text_len, unsigned int start,
	size_t len)
{
size_t	i;
char	*aux;

i = 0;
if (start >= text_len)
{
	aux = malloc(1);
	if (!aux)
		return (NULL);
	aux[0] = '\0';
	return (aux);
}
if (len > text_len - start)
	len = text_len - start;
aux = malloc(len + 1);
if (!aux)
	return (NULL);
while (i < len)
{
	aux[i] = s[i + start];
	i++;
}
aux[i] = '\0';
return (aux);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
size_t	text_len;

if (!s)
	return (NULL);
text_len = ft_strlen(s);
return (new_str(s, text_len, start, len));
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[j + i] = s2[j];
		j++;
	}
	str[j + i] = '\0';
	return (str);
}
