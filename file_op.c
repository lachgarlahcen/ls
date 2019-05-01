/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 02:17:54 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/17 02:25:21 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		file_type(struct stat st)
{
	if (S_ISDIR(st.st_mode))
		return ('d');
	if (S_ISLNK(st.st_mode))
		return ('l');
	if (S_ISCHR(st.st_mode))
		return ('c');
	if (S_ISBLK(st.st_mode))
		return ('b');
	if (S_ISFIFO(st.st_mode))
		return ('f');
	if (S_ISSOCK(st.st_mode))
		return ('f');
	return ('-');
}

int			six_month(time_t t)
{
	time_t		t1;
	long		diff;

	t1 = time(NULL);
	diff = t1 - t;
	if ((diff > 0 && diff > 15780000) || (diff < 0 && diff < -15780000))
		return (1);
	return (0);
}

void		get_time(time_t t)
{
	char *tm;
	char **tab;
	char *hour;
	char **tab1;

	tm = ctime(&t);
	tab = ft_strsplit(tm, ' ');
	ft_printf("%3s", tab[1]);
	ft_printf("%3s", tab[2]);
	tab[4][4] = '\0';
	if (!six_month(t))
	{
		tab1 = ft_strsplit(tab[3], ':');
		hour = ft_strjoin_f(tab1[0], ":", 0, 0);
		hour = ft_strjoin_f(hour, tab1[1], 1, 0);
		ft_printf("%6s ", hour);
		free(hour);
		free_2d_str(tab1);
	}
	else
		ft_printf("%6s ", tab[4]);
	free_2d_str(tab);
}

void		get_size(struct stat st, int max, int major)
{
	char c;
	char *nbr;

	c = file_type(st);
	if (c == 'b' || c == 'c')
	{
		ft_printf("%3d,%4d ", major(st.st_rdev), major(st.st_rdev));
		return ;
	}
	if (major > 0)
		max += 7;
	nbr = ft_itoa_base(st.st_size, 10);
	put_space(max, nbr, 0);
	free(nbr);
}

t_max_ll	*get_max(t_ls *ls, int cunt)
{
	t_max_ll		*max;
	struct stat		st;
	int				i;
	char			*path;

	max = (t_max_ll *)malloc(sizeof(t_max_ll));
	i = 0;
	max->lnk = 0;
	max->size = 0;
	max->usr = 0;
	max->grp = 0;
	max->minor = 0;
	max->major = 0;
	while (i < cunt)
	{
		path = ft_strjoin_f(ls->path, "/", 0, 0);
		path = ft_strjoin_f(path, ls->tab[i].d_name, 1, 0);
		if (lstat(path, &st) == 0)
		{
			max = comp_max(st, max);
		}
		free(path);
		i++;
	}
	return (max);
}
