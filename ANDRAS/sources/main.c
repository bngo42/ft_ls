/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:22:07 by acottier          #+#    #+#             */
/*   Updated: 2016/06/24 16:37:27 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_free_list(t_arg *lst)
{
	t_arg	*following;

	while (lst)
	{
		free(lst->path);
		following = lst->next;
		free(lst);
		lst = following;
	}
}

int				main(int argc, char **argv)
{
	int		err;
	char	errchar;
	char	*options;
	t_arg	*arguments;

	(void)argc;
	options = ft_treat_opts(argv, &err, &errchar);
	if (err != 0)
		ft_error(err, argv, errchar, 0);
	else
	{
		printf("Options format is OK. \n");
		if (!options || !options[1])
			printf("No options.\n");
		else
			printf("Options : <%s>\n", options);
		arguments = ft_treat_args(argv, options);
		printf("Arg list created.\n\n-----\n");
		ft_global_treat(options, arguments);
		printf("-----\n\nTreatement over.\n");
		ft_free_list(arguments);
		printf("Argument list freed.\n");
	}
	free(options);
	printf("Options array freed.\n");
	printf("\nProgram finished.\n");
	return (0);
}
