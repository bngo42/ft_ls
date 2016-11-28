/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:50 by bngo              #+#    #+#             */
/*   Updated: 2016/11/28 15:00:02 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*ft_check_arg(char **argv)
{
	char *arg;
	int i;
	int j;
	int k;

	if (!(arg = (char*)malloc(sizeof(char) * 6)))
		return (NULL);
	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			j++;
			while (argv[i][j])
			{
				if (argv[i][j] == '-')
				{
					ft_putendl("Erreur\n");
					exit(0);
				}
				else if (ft_strchr("lRart", argv[i][j]) && !ft_strchr(arg, argv[i][j]))
					arg[k++] = argv[i][j];
				j++;
			}
		}
		else
			exit(0);
		i++;
	}
	arg[k] = '\0';
	printf("arg = %s\n", arg);
	return (arg);
}

int			main(int argc, char **argv)
{
	t_rep	*r;
	char	*arg;


	arg = ft_check_arg(argv);
	if (!(r = (t_rep*)malloc(sizeof(t_rep))))
		return (-1);
	if (!(r->dir = opendir(argv[1])))
		return (-1);
	while ((r->file = readdir(r->dir)))
	{
		ft_putendl(r->file->d_name);
	}
	if (!(closedir(r->dir)))
		return (-1);
	return (0);
}
