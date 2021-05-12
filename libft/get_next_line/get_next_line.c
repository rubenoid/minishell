/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:54:13 by rvan-sch      #+#    #+#                 */
/*   Updated: 2021/03/05 15:55:58 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif

static void	buff_move(char *s, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		s[i] = s[start + i];
		i++;
	}
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}

static int	buff_exists(char *buff, char **line)
{
	char	*tmp;

	buff_move(buff, 1, BUFFER_SIZE - 1);
	tmp = ft_substr(buff, 0, ft_line_length(buff));
	if (!tmp)
		return (-1);
	*line = ft_strjoin_freefirst(*line, tmp);
	free(tmp);
	if (!line)
		return (-1);
	buff_move(buff, ft_line_length(buff), BUFFER_SIZE - ft_line_length(buff));
	if (buff[0] == '\n')
		return (1);
	return (0);
}

static int	fill_line(char *buff, char **line)
{
	char	*tmp;

	tmp = ft_substr(buff, 0, ft_line_length(buff));
	if (!tmp)
		return (-1);
	*line = ft_strjoin_freefirst(*line, tmp);
	free(tmp);
	if (!line)
		return (-1);
	return (0);
}

static int	ft_init(int fd, char **line, char *buff)
{
	int	ret;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || fd >= OPEN_MAX || \
		(read(fd, 0, 0) < 0))
		return (-1);
	*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	if (buff[0] == '\n')
	{
		ret = buff_exists(buff, line);
		if (ret > 0)
			return (1);
		else if (ret == -1)
			return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	int			ret;

	ret = ft_init(fd, line, buff[fd]);
	if (ret == 1 || ret == -1)
		return (ret);
	ret = read(fd, buff[fd], BUFFER_SIZE);
	while (ret > 0)
	{
		if (fill_line(buff[fd], line) == -1)
			return (-1);
		if (ft_line_length(buff[fd]) < BUFFER_SIZE)
		{
			buff_move(buff[fd], ft_line_length(buff[fd]),
				BUFFER_SIZE - ft_line_length(buff[fd]));
			if (buff[fd][0] == 0)
				return (0);
			return (1);
		}
		buff_move(buff[fd], 0, 0);
		ret = read(fd, buff[fd], BUFFER_SIZE);
	}
	if (ret == -1)
		return (-1);
	return (0);
}
