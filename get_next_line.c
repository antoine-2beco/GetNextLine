/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:33 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/29 12:07:12 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_printline(t_list *stash) 
{
	char	temp;

	while (stash->content != '\n')
	{
		temp = stash->content;
		write(1, &temp, 1);
		stash = stash->next;
	}
	return (stash->next);
}

char	*get_next_line(int fd)
{
	t_list	*stash;
	char	buf[BUFFER_SIZE];
	int		rdl;
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (!s)
	{
		rdl = read(fd, buf, BUFFER_SIZE);
		while (i <= BUFFER_SIZE)
		{
			ft_addback(&stash, buf[i]);
			if (buf[i] == '\n')
			{
				stash = ft_printline(stash);
				s = 1;
			}
			i++;
		}
	}
	close(fd);
}

int	main(get_next_line)
{
	get_next_line("test.txt");
}