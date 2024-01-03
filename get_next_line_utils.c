/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:30 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/03 17:25:21 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	if (s == NULL || *s == '\0')
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)(ft_strlen(s)))
		i = 1;
	else if (len < ft_strlen(s) - start)
		i = len + 1;
	else
		i = (ft_strlen(s) - start) + 1;
	str = (char *)malloc(i);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	k = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s1 && s1[j] != '\0')
		str[i++] = s1[j++];
	while (s2 && s2[k] != '\0')
		str[i++] = s2[k++];
	str[i] = '\0';
	return (str);
}
