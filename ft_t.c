/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:59:12 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/19 21:14:53 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		swap_dirnet(struct dirent *tab, int i)
{
	struct dirent	temp;

	temp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = temp;
}

void		ls_t(t_ls ls, struct dirent *tab, int len)
{
	int				i;
	struct stat		statbuf;
	struct stat		statbuff;
	char			*str2;
	char			*str3;

	i = -1;
	while (++i < len - 1)
	{
		str2 = ft_strjoin_f(ls.path, ft_strjoin("/", ls.tab[i].d_name), 0, 1);
		str3 = ft_strjoin_f(ls.path,
				ft_strjoin("/", ls.tab[i + 1].d_name), 0, 1);
		lstat(str2, &statbuf);
		lstat(str3, &statbuff);
		if (statbuf.st_mtime < statbuff.st_mtime)
		{
			swap_dirnet(tab, i);
			i = 0;
			free(str2);
			free(str3);
			continue ;
		}
		free(str2);
		free(str3);
	}
}
