/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:56:54 by bngo              #+#    #+#             */
/*   Updated: 2016/09/20 18:56:19 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
t_file	*ft_push_back(t_file *lst, t_file *elem)
{
	return (lst);
}

t_file	*ft_new_elem(char *name)
{
	t_file *new;

	return (new);
}

int		ft_get_param(char *str)
{
	//0 ERROR
	//1 -l
	//2 -R
	//3 -a
	//4 -r
	//5 -t
	int state[6];
	const char flag[6] = {'l','R','a','r','t'};
	int i;
	int	j;

	i = 0;
	while (i < 4)
		state[0] = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			i++;

		i++;
	}
	return (0);
}
*/
char	*ft_combine_param(int count, char **argv)
{
	char *result;
	int i;

	i = 1;
	ft_putendl("DEBUG");
	result = "";
	while (i < count)
		result = ft_strjoin(result, argv[i++]);
	printf("<|%s|>\n", result);
	return (result);
}

int		ft_check_param(int count, char **argv)
{
	char *result;
	result = ft_combine_param(count, argv);
	return (1);
}
/*
int		ft_list_file(DIR *rep)
{
	struct dirent *data;

	while ((data = readdir(rep)) != NULL)
	{
		ft_putstr(data->d_name);
		ft_putchar('\t');
	}
	return (0);
}
*/
int		main(int argc, char **argv)
{
	
	if (!(ft_check_param(argc, argv)))
		return(-1);
	/*if (argc > 0)
	{
		if(!(rep = opendir(argv[1])))
			return (-1);
		
	}*/
	return (0);
}
