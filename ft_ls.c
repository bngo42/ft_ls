/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:56:54 by bngo              #+#    #+#             */
/*   Updated: 2016/09/26 14:55:54 by bngo             ###   ########.fr       */
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

	if(!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->name = name;
	new->date_create = 0;
	new->next = NULL;
	return (new);
}
*/

int		ft_combine_param(char **argv, char **result)
{
	char	*flag;
	char	*arg;
	int		i;
	int		j;

	i = 0;
	(*result) = "";
	flag = "lRart";
	arg = ft_strnew(0);
	ft_putendl("caca");
	while (argv[i++] && !ft_strstr((*result), "--") && argv[i][0] == '-')
	{
		j = 0;
		ft_putendl("caca");
		while (argv[i][j])
		{
			if (argv[i][j] != '-' && !ft_strchr(flag, argv[i][j]))
			{
				//ft_putendl("cond2");
				return (-1);// Options non supporte
			}
			else if (argv[i][j] == '-' && j > 0 && (argv[i][j - 1] != ' ' && argv[i][j - 1] != '-'))
			{
				//ft_putendl("cond3");// Pas d'espace avant '-'
				return (-1);
			}
			else
			{
				//ft_putendl("cond4");
				arg[0] = argv[i][j];
				(*result) = ft_strjoin((*result), arg);
			}
			j++;
		}
		ft_strdel(&argv[i]);
	}
	ft_putendl("caca");
	return (0);
}

int		ft_check_param(char **argv, int *arg)
{
	char	*result;
	char	*flag;
	int		i;
	int		j;

	if ((ft_combine_param(argv, &result)) == -1)
		return (-1);
	flag = "lRart";
	i = 0;
	while (i < 5)
		arg[i++] = 0;
	i = 0;
	while (result[i++])
	{
		j = 0;
		while (result[i] != '-' && flag[j])
		{
			ft_putendl("juju");
			if (result[i] == flag[j])
				arg[j] = 1;
			j++;
		}
	}
	j = 0;
	while (j < 5)
		ft_putnbr(arg[j++]);
	ft_putchar('\n');
	return (1);
}


int		ft_list_file(DIR *rep)
{
	struct dirent *data;

	while ((data = readdir(rep)) != NULL)
	{
		ft_putstr(data->d_name);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	return (0);
}
int		main(int argc, char **argv)
{
	int		*arg;
	char	**value;
	int		i;
	DIR		*rep;

	i = -1;
	value = (char**)malloc(sizeof(char*) * (argc - 1));
	arg = (int*)malloc(sizeof(int) * 5);
	while (++i < (argc - 1))
		value[i] = ft_strdup(argv[i + 1]);
	if (!(ft_check_param(value, arg)))
	{
		ft_putendl("invalid param");
		return (1);
	}
	for(int p = 0; p < argc - 1; p++)
		printf("argv[%i] = %s\n", p, value[p]);
	i = 0;
	(void)rep;
	/*while (i < (argc - 1))
	{
		if (value[i] != NULL)
		{
			if ((rep = opendir(value[i])))
				ft_list_file(rep);
			else
				{
					ft_putstr("ls: ");
					ft_putstr(value[i]);
					ft_putendl(": No such file or directory");
				}
		}
		i++;
	}*/
	return (0);
}	
