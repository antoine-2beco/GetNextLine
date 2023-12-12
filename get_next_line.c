/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:33 by ade-beco          #+#    #+#             */
/*   Updated: 2023/12/12 11:49:54 by ade-beco         ###   ########.fr       */
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

	old_stash = *stash;
	old_stash_len = ft_strlen(old_stash);
	i = (old_stash_len - (rdc - nli));
	ret = ft_substr(old_stash, 0, i);
	if (nli == -1)
		i++;
	*stash = ft_substr(old_stash, i, old_stash_len);
	printf("new stash : %s\n", *stash);
	printf("rdc : %i		nli : %i", rdc, nli);
	if (rdc == 0 && nli == 0)
		return("(null)");
	return (ret);
}

static int	ft_check_nl(char *stash, int rdc)
{
	int	i;

	i = 0;
	while (i < rdc)
	{
		printf("	c = %c	i = %i\n", stash[i], i);
		if (stash[i] == '\n')
			return (++i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE + 1];
	int			rdc;
	int			nli;

	printf("\n\n\n\nold stash : %s\n", stash);
	while (1)
	{
		rdc = read(fd, buf, BUFFER_SIZE);
		printf("rdc = %i\n", rdc);
		printf("buf = %s\n", buf);
		if (rdc != 0)
		{
			stash = ft_strjoin(stash, ft_substr(buf, 0, rdc));
			printf("s = %s\n", stash);
			nli = ft_check_nl(buf, rdc);
			printf("nli = %i\n", nli);
			if (nli != -1)
				return (ft_get_return(&stash, nli, rdc));
		}
		else if (rdc == 0)
			return (ft_get_return(&stash, ft_strlen(stash), rdc));
	}
}
