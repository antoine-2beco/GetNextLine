/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:33 by ade-beco          #+#    #+#             */
/*   Updated: 2023/12/11 15:10:03 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

static char	*ft_get_return(char *stash, int nli)
{
	char	*ret;
	int		i;

	i = (ft_strlen(stash) - (BUFFER_SIZE - nli));
	ret = ft_substr(stash, 0, i);
	while (stash[i] == '\n')
		i++;
	stash = ft_substr(stash, i, ft_strlen(stash));
	printf("new stash : %s\n\n", stash);
	ft_putstr(ret);
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
			return (i);
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
		if (rdc != 0)
		{
			stash = ft_strjoin(stash, buf);
			printf("s = %s\n", stash);
			nli = ft_check_nl(buf, rdc);
			printf("nli = %i\n", nli);
			if (nli != -1)
				return (ft_get_return(stash, nli));
		}
		else if (rdc == 0)
			return (ft_get_return(stash, ft_strlen(stash)));
	}
}
