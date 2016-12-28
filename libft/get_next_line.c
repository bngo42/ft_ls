/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:27:56 by lvalenti          #+#    #+#             */
/*   Updated: 2016/03/14 12:30:59 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int		read_text(int const fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	int		nb_read;
	char	*point;

	while ((nb_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb_read] = '\0';
		point = *str;
		*str = ft_strjoin(*str, buf);
		ft_strdel(&point);
		if (ft_strchr(*str, '\n') != NULL)
			return (nb_read);
	}
	if (nb_read <= 0)
		return (nb_read);
	return (nb_read);
}

char	*get_line(char **str)
{
	char	*buf;
	char	*end_line;
	char	*point;

	end_line = ft_strchr(*str, '\n');
	point = NULL;
	if (end_line != NULL)
	{
		*end_line = '\0';
		point = end_line;
		end_line = ft_strdup(end_line + 1);
	}
	buf = ft_strdup(*str);
	point != NULL ? *point = '\n' : 0;
	free(*str);
	point = NULL;
	*str = NULL;
	if (end_line != NULL)
		*str = end_line;
	return (buf);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str[256];
	int				nb_read;

	if (fd > 255 || BUFF_SIZE <= 0 || !line || fd < 0)
		return (-1);
	nb_read = 0;
	if (!str[fd])
	{
		str[fd] = (char *)malloc(sizeof(char));
		*str[fd] = '\0';
	}
	if (!ft_strchr(str[fd], '\n'))
	{
		if ((nb_read = read_text(fd, &str[fd])) < 0)
			return (-1);
	}
	if (ft_strchr(str[fd], '\n') || (*str[fd] != '\0' && nb_read == 0))
	{
		*line = get_line(&str[fd]);
		return (1);
	}
	ft_strdel(&str[fd]);
	return (0);
}
