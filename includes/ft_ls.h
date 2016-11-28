/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:13:18 by bngo              #+#    #+#             */
/*   Updated: 2016/11/28 12:10:53 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <stdio.h>

typedef struct		s_rep
{
	DIR				*dir;
	struct dirent	*file;
	void			*data;
	struct s_rep	*next;
	struct s_rep	*prev;
}					t_rep;

#endif
