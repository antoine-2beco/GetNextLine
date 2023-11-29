/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:30 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/29 16:44:26 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	unsigned long	i;
	char			*tab;

	i = -1;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tab)
		return (NULL);
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	i = 0;
	j = 0;
	k = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	while (s2[k] != '\0')
		str[i++] = s2[k++];
	str[i] = '\0';
	return (str);
}

void	ft_putstr(char *s, unsigned int max_l)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && i < max_l)
	{
		write(1, &s[i], 1);
		i++;
	}
}
