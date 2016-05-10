/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:35:46 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/11 00:02:33 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>

typedef struct	s_options
{
	int			l;
	int			r;
	int			maj_r;
	int			a;
	int			t;
	int			maj_g;
	int			u;
	int			f;
	int			g;
	int			d;
	char		**files;
	char		**rep;
}				t_options;

t_options		get_options(int argc, char **argv);
void			sort_by_ascii(char **tab, int i);

#endif
