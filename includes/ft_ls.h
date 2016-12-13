/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:13:18 by bngo              #+#    #+#             */
/*   Updated: 2016/12/12 19:09:35 by lvalenti         ###   ########.fr       */
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
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
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
	mode_t			mode;
	struct passwd	*user;
	struct stat		filestat;
	DIR				*dir;
	struct dirent	*file;
	void			*data;
	struct s_rep	*next;
	struct s_rep	*prev;
}					t_rep;

void				funct_l();
void				funct_gr();
void				funct_a();
// void				funct_pr();
void				funct_t();
void				ft_printlst(t_rep *lst, t_opt *opt);
void				ft_list_end(t_rep **begin, t_rep *new);
void				aff_stat(t_rep *r);
void				file_type(struct stat filestat);
void				ft_get_mode(t_rep *data);
void				aff_stat2(t_rep *data);
char				*modif_time(char *time);
void				ft_sort_list(t_rep *r);

#endif
