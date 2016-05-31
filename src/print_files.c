/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:41 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/31 20:59:35 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			count_files(t_op options, int *len)
{
	int file_nbr;
	int	i;
	int	temp;

	i = 0;
	file_nbr = 0;
	while (options.files[i] != NULL)
	{
		if ((temp = ft_strlen(options.files[i])) > *len)
			*len = temp;
		file_nbr += 1;
		i++;
	}
	i = 0;
	if (options.flag)
	{
		while (options.rep[i] != NULL)
		{
			if ((temp = ft_strlen(options.rep[i])) > *len)
				*len = temp;
			file_nbr += 1;
			i++;
		}
	}
	return (file_nbr);
}

static char *fill_tab_elem(t_op o, int *i, int *j)
{
	char	*tab;

	tab = NULL;
	if (o.files[*i] == NULL && o.rep[*j] && o.flag == 1)
	{
		tab = ft_strdup(o.rep[*j]);
		*j += 1;
	}
	else if (o.flag == 0 || (o.rep[*j] == NULL && o.files[*i]))
	{
		tab = ft_strdup(o.files[*i]);
		*i += 1;
	}
	else if (ft_strcmp(o.files[*i], o.rep[*j]) > 0 && o.flag == 1)
	{
		tab = ft_strdup(o.rep[*j]);
		*j += 1;
	}
	else if (o.files[*i])
	{
		tab = ft_strdup(o.files[*i]);
		*i += 1;
	}
	return (tab);
}

static char	***fill_tab(t_op o, int l, int L, int mod)
{
	int				i[2];
	int				j;
	int				k;
	char 			***tab;

	i[0] = 0;
	j = 0;
	i[1] = 0;
	if (mod == 0)
		L -= 1;
	tab = (char***)malloc(sizeof(char**) * l + 1);
	while (j < l)
	{
		k = -1;
		tab[j] = (char**)malloc(sizeof(char*) * L + 1);
		while (++k < L)
		{
			tab[j][k] = NULL;
			if (o.files[i[0]] || o.rep[i[1]])
				tab[j][k] = fill_tab_elem(o, &i[0], &i[1]);
		}
		tab[j++][k] = NULL;
	}
	tab[j] = NULL;
	return (tab);
}

static void	display_tab(char ***tab, int len)
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
				ft_printf("%-*s", len, tab[i][j]);
			else
				break;
		}
		if (tab[0][j])
			ft_putchar('\n');
	}
	//////////// func free_tab
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
	display_tab(tab, len);
}
