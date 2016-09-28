/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:23:48 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 17:52:24 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	copy_options(t_op *o, t_op options, char *name)
{
	o->l = options.l;
	o->r = options.r;
	o->maj_r = options.maj_r;
	o->a = options.a;
	o->t = options.t;
	o->u = options.u;
	o->g = options.g;
	o->c = options.c;
	o->p = options.p;
	o->one = options.one;
	o->flag = 1;
	if (options.path != NULL)
	{
		o->path = ft_strjoin(options.path, "/");
		o->path = ft_strjoin(o->path, name);
	}
	else
		o->path = ft_strdup(name);
	o->files = NULL;
}

void	flag_options2(t_op *options, char c)
{
	if (c == 'c')
	{
		options->c = 1;
		options->u = 0;
	}
	else if (c == '1')
		options->one = 1;
	else if (c == 'p')
		options->p = 1;
}
