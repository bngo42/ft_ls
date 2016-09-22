/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:56:54 by bngo              #+#    #+#             */
/*   Updated: 2016/09/22 15:53:46 by bngo             ###   ########.fr       */
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
char	*ft_combine_param(char **argv)
{
	char	*result;
	char	*flag;
	char	*arg;
	int		i;
	int		j;

	i = 0;
	result = "";
	flag = "lRart";
	arg = ft_strnew(0);
	while (argv[++i] && !ft_strstr(result, "--"))
	{
		j = 0;
		if (argv[i][0] != '-')
			return (NULL);//Pas de '-' avant les options
		while (argv[i][j])
		{
			if (argv[i][j] != '-' && !ft_strchr(flag, argv[i][j]))
			{
				ft_putendl("cond2");
				return (NULL);// Options non supporte
			}
			else if (argv[i][j] == '-' && j > 0 && (argv[i][j - 1] != ' ' && argv[i][j - 1] != '-'))
			{
				ft_putendl("cond3");// Pas d'espace avant '-'
				return (NULL);
			}
			else
			{
				ft_putendl("cond4");
				arg[0] = argv[i][j];
				result = ft_strjoin(result, arg);
			}
			j++;
		}
	}
	j = 0;
	if (result == NULL)
		return (NULL);
	printf("arguments found: <|%s|>\n", result);
	return (result);
}

int		ft_check_param(char **argv)
{
	char	*result;
	char	*flag;
	int		state[5];
	int		i;
	int		j;


	result = ft_combine_param(argv);
	flag = "lRart";
	i = 0;
	while (i < 5)
		state[i++] = 0;
	i = 0;
	while (result[i++])
	{
		j = 0;
		while (result[i] != '-' && flag[j++])
		{
			if (result[i] == flag[j])
				state[j] = 1;
		}
	}
	j = 0;
	while (j < 5)
		ft_putnbr(state[j++]);
	ft_putchar('\n');
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
	(void)argc;
	if (!(ft_check_param(argv)))
		return(-1);
	/*if (argc > 0)
	{
		if(!(rep = opendir(argv[1])))
			return (-1);
		
	}*/
	return (0);
}	
