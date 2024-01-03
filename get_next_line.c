/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:44:31 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/03 17:23:37 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_line(char *stack)
{
	int	i;

	i = 0;
	if (!stack || stack == NULL)
		return (-1);
	while (stack[i] != '\0')
	{
		if (stack[i] == '\n')
			return (++i);
		i++;
	}
	return (-1);
}

static char	*return_line(char **stack)
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
	static char	*stack;
	char		heap[BUFFER_SIZE + 1];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stack)
		if (check_line(stack))
			return_line(&stack);
	if (read_file(fd, &stack, heap) == -1)
	{
		free (stack);
		stack = NULL;
		return (NULL);
	}
	else
	{
		ret = return_line(&stack);
		if (ft_strlen(stack) == 0)
		{
			free (stack);
			stack = NULL;
		}
		return (ret);
	}
}
