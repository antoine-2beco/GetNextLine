/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:44:31 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/09 23:12:07 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// -1 == no /n in heap || int == index of /n
static int	check_line(char *stack)
{
	int	i;

	i = 0;
	while (stack && stack[i] != '\0')
	{
		if (stack[i] == '\n')
			return (++i);
		i++;
	}
	return (-1);
}

static char	*get_line(char **stack)
{
	int		i;
	char	*old_stack;
	char	*ret;
	int		old_stack_len;

	i = check_line(*stack);
	if (i == -1 && ft_strlen(*stack) == 0)
		return (NULL);
	else
	{
		old_stack = *stack;
		old_stack_len = ft_strlen(old_stack);
		ret = ft_substr(old_stack, 0, i);
		*stack = ft_substr(old_stack, i, old_stack_len);
		free (old_stack);
		old_stack = NULL;
	}
	return (ret);
}

// -1 == read error || 0 == no more to read || 1 == line readed
static int	read_file(int fd, char **stack, char *heap)
{
	char	*temp_stack;
	int		ret;

	while (1)
	{
		ret = read(fd, heap, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (ret);
		heap[ret] = '\0';
		if (*stack)
		{
			temp_stack = *stack;
			*stack = ft_strjoin(temp_stack, heap);
			free(temp_stack);
			temp_stack = NULL;
		}
		else
			*stack = ft_substr(heap, 0, ft_strlen(heap));
		if (ret < BUFFER_SIZE)
			return (0);
		if (check_line(*stack) != -1)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*heap;
	static char	*stack;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT32_MAX)
		return (NULL);
	heap = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!heap || read_file(fd, &stack, heap) == -1)
	{
		free (stack);
		stack = NULL;
		ret = NULL;
	}
	else
	{
		ret = get_line(&stack);
		if (ft_strlen(stack) == 0 || !ret)
		{
			free(stack);
			stack = NULL;
		}
	}
	free(heap);
	heap = NULL;
	return (ret);
}
