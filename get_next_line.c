/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:33 by ade-beco          #+#    #+#             */
/*   Updated: 2023/12/14 16:19:20 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

static char	*ft_get_return(char **stash, int nli, int rdc)
{
	char	*ret;
	int		i;
	char	*old_stash;
	int		old_stash_len;

	if (rdc == 0 && nli == 0)
		return (NULL);
	old_stash = *stash;
	old_stash_len = ft_strlen(old_stash);
	i = (old_stash_len - (rdc - nli));
	ret = ft_substr(old_stash, 0, i);
	*stash = ft_substr(old_stash, i, old_stash_len);
	return (ret);
}

static int	ft_check_nl(char *stash, int rdc)
{
	int	i;

	i = 0;
	while (i < rdc)
	{
		if (stash[i] == '\n')
			return (++i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	int			rdc;
	int			nli;

	rdc = 0;
	if (stash)
	{
		nli = ft_check_nl(stash, ft_strlen(stash));
		if (nli != -1)
		{
			ret = ft_get_return(&stash, nli, ft_strlen(stash));
			rdc = -1;
		}
	}
	while (rdc != -1)
	{
		rdc = read(fd, buf, BUFFER_SIZE);
		// one char bug et leaks
		if (rdc == -1)
			return (NULL);
		if (rdc != 0)
		{
			stash = ft_strjoin(stash, ft_substr(buf, 0, rdc));
			nli = ft_check_nl(buf, rdc);
			if (nli != -1)
			{
				ret = ft_get_return(&stash, nli, rdc);
				break ;
			}
		}
		else if (rdc == 0)
		{
			ret = ft_get_return(&stash, ft_strlen(stash), rdc);
			break ;
		}
	}
	if (ret == NULL)
	{
		free (stash);
		return (NULL);
	}
	return (ret);
}
