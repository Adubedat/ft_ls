/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:41 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 20:23:40 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			count_files(t_op options, int *len)
{
	int		file_nbr;
	t_files	*tmp;
	int		temp;

	tmp = options.files;
	file_nbr = 0;
	while (tmp != NULL)
	{
		if (options.flag == 1 || (tmp->type != 0 && tmp->type != 3))
		{
			if ((temp = ft_strlen(tmp->file_name)) > *len)
				*len = temp;
			file_nbr += 1;
		}
		tmp = tmp->next;
	}
	return (file_nbr);
}

static char	*fill_tab_elem(t_op o, t_files **tmp)
{
	char	*tab;

	tab = NULL;
	while ((*tmp) != NULL && !(o.flag == 1 || ((*tmp)->type != 0
	&& (*tmp)->type != 3)))
		(*tmp) = (*tmp)->next;
	if ((*tmp) == NULL)
		return (tab);
	tab = ft_strdup((*tmp)->file_name);
	if (o.p == 1 && (*tmp)->type == 0)
		tab = ft_strjoin_free_s1(tab, "/");
	(*tmp) = (*tmp)->next;
	return (tab);
}

static char	***fill_tab(t_op o, int l, int ll, int mod)
{
	t_files			*tmp;
	int				j;
	int				k;
	char			***tab;

	j = 0;
	tmp = o.files;
	if (mod == 0)
		ll -= 1;
	tab = (char***)malloc(sizeof(char**) * l + 1);
	while (j < l)
	{
		k = -1;
		tab[j] = (char**)malloc(sizeof(char*) * ll + 1);
		while (++k < ll)
		{
			tab[j][k] = NULL;
			if (tmp != NULL)
				tab[j][k] = fill_tab_elem(o, &tmp);
		}
		tab[j++][k] = NULL;
	}
	tab[j] = NULL;
	return (tab);
}

static void	display_tab(char ***tab, int len, t_op o)
{
	int	i;
	int	j;

	j = -1;
	if (tab[0][0] == NULL)
		return ;
	while (tab[0][++j])
	{
		i = -1;
		while (tab[++i])
		{
			if (tab[i][j])
			{
				ft_printf("%-*s", len, tab[i][j]);
				if (o.one == 1)
					ft_putchar('\n');
			}
			else
				break ;
		}
		if (tab[0][j] && o.one == 0)
			ft_putchar('\n');
	}
}

void		print_files(t_op options)
{
	int				file_nbr;
	int				len;
	char			***tab;
	struct winsize	size;

	len = 0;
	file_nbr = 0;
	ioctl(0, TIOCGWINSZ, &size);
	file_nbr = count_files(options, &len);
	len = (len / 8 + 1) * 8;
	if (size.ws_col < len)
		size.ws_col = len;
	tab = fill_tab(options, size.ws_col / len,
			1 + file_nbr / (size.ws_col / len), file_nbr % (size.ws_col / len));
	display_tab(tab, len, options);
}
