/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:13:18 by bngo              #+#    #+#             */
/*   Updated: 2016/12/01 12:02:44 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# define DBUG1 write(1, "debug1\n", 8);
# define DBUG2 write(1, "debug2\n", 8);
# define DBUG3 write(1, "debug3\n", 8);
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct		s_opt
{
	int				l;
	int				gr;
	int				a;
	int				pr;
	int				t;
}					t_opt;

typedef struct		s_rep
{
	struct stat		*filestat;
	DIR				*dir;
	struct dirent	*file;
	void			*data;
	struct s_rep	*next;
	struct s_rep	*prev;
}					t_rep;

void				funct_l();
void				funct_gr();
void				funct_a();
void				funct_pr();
void				funct_t();

#endif
