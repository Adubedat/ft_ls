/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:23:48 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/21 19:35:58 by adubedat         ###   ########.fr       */
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
	o->maj_g = options.maj_g;
	o->u = options.u;
	o->f = options.f;
	o->g = options.g;
	o->d = options.d;
	o->flag = options.flag;
	if (options.path != NULL)
	{
		o->path = ft_strjoin(options.path, "/");
		o->path = ft_strjoin(o->path, name);
	}
	else
		o->path = ft_strdup(name);
	o->files = NULL;
}
