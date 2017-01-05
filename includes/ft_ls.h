/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:02:05 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/05 12:08:56 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_opt
{
	int				l;
	int				gr;
	int				a;
	int				pr;
	int				t;
	int				len[8];
	int				nb_ac;
	int				nb_dir;
	int				count;
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

void				ft_printlst(t_rep *lst, t_opt *opt);
void				add_list(t_rep *begin, char *str);
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
void				free_lst(t_rep *lst);
void				sort_ascii(t_rep *tmp, t_rep *new);
void				display_long(t_rep *data, int len[6]);
void				show_info(char *str, int len, int state, int state2);
void				funct_l(t_rep *r, t_opt *opt);
void				funct_l_2(t_rep *tmp, t_opt *opt);
void				funct_t(t_rep *lst);
void				funct_t_2(t_rep *tmp, t_rep *lst);
void				funct_gr(t_rep *lst, t_opt *opt);
void				funct_gr_2(t_rep *tmp, t_opt *opt);
t_rep				*funct_pr(t_rep *r);
void				swap_link(t_rep *lst);
void				reverse_link(t_rep *lst);
int					read_arg(char *path, t_opt *opt);
int					read_rep(t_rep *r, t_opt *opt, char *path);
void				assign_opt(t_opt *opt, t_rep *r);

#endif
