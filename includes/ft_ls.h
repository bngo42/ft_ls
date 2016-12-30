/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:02:05 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/30 12:05:36 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
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
	int				len[8];
}					t_opt;

typedef struct		s_rep
{
	char			*name;
	int				flag;
	char			*name2;
	char			*argv;
	int				major;
	int				minor;
	int				type;
	mode_t			mode;
	struct passwd	*user;
	struct stat		filestat;
	DIR				*dir;
	int				time_s;
	int				time_ns;
	struct s_rep	*next;
	struct s_rep	*prev;
}					t_rep;

void				funct_l();
void				funct_gr();
void				funct_a();
void				funct_t();
void				ft_printlst(t_rep *lst, t_opt *opt);
void				add_list(t_rep **begin, t_rep *new);
void				aff_stat(t_rep *data, int len[6]);
void				file_type(struct stat filestat, t_rep *data);
void				ft_get_mode(t_rep *data);
void				aff_stat2(t_rep *data);
char				*modif_time(char *time);
char				*ft_check_arg(char **argv);
int					ft_check_opt(char *arg, t_opt *opt);
char				*get_date(t_rep *data);
void				get_len(t_rep *data, t_opt *opt);
int					read_arg(char *path, t_opt *opt);

#endif
