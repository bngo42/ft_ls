/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 14:07:30 by bngo              #+#    #+#             */
/*   Updated: 2016/09/01 18:24:36 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char **line, char **buff)
{
	char	*tmp;
	char	*tmp2;

	if ((tmp = ft_strchr(*buff, '\n')))
	{
		*tmp = '\0';
		tmp2 = ft_strdup(tmp + 1);
		*line = ft_strdup(*buff);
		ft_strdel(buff);
		*buff = ft_strdup(tmp2);
		free(tmp2);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*buff = NULL;
	char		buffer[BUFF_SIZE + 1];

	if (buff == NULL)
		buff = ft_strnew(0);
	if (fd < 0 || fd == 1 || fd == 2 || line == NULL)
		return (-1);
	if (check_line(line, &buff))
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		buff = ft_strjoin(buff, buffer);
		if (check_line(line, &buff) == 1)
			return (1);
	}
	if (ret == -1)
		return (-1);
	if (*buff == '\0')
		return (0);
	*line = ft_strdup(buff);
	ft_strdel(&buff);
	return (1);
}
