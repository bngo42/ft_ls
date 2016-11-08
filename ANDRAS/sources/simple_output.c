/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:50:04 by acottier          #+#    #+#             */
/*   Updated: 2016/06/22 14:39:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_simple_output(t_arg *args, char *opts)
{
	ft_file_walkthrough(args, opts);
	ft_dir_walkthrough(args);
}
