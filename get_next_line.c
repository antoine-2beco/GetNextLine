/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:33 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/29 17:32:44 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

char	*get_next_line(int fd)
{
	char			*stash;
	char			buf[BUFFER_SIZE + 1];
	int				rdl;
	int				i;
	unsigned int	j;
	unsigned int	rdls;

	i = BUFFER_SIZE;
	j = 0;
	rdls = 0;
	while (j == rdls)
	{
		i = 0;
		rdl = read(fd, buf, BUFFER_SIZE);
		if ((!rdls && !rdl) || rdl == -1)
			return (NULL);
		if (!rdl)
			break ;
		rdls += rdl;
		printf("buf : %s\n", buf);
		printf("rdl : %i\n", rdl);
		printf("rdls : %i\n", rdls);
		while (i < BUFFER_SIZE && buf[i] != '\n')
			i++;
		printf("i : %i\n", i);
		j = rdls - (BUFFER_SIZE - i);
		if (rdls != BUFFER_SIZE)
			stash = ft_strjoin(stash, buf);
		else
			stash = ft_strdup(buf);
	}
	ft_putstr(stash, j);
	close(fd);
	return (stash);
}