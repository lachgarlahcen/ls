/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 02:12:03 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/17 02:14:19 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		get_acl_xt(char *path)
{
	acl_t		acl;
	acl_entry_t	d;
	ssize_t		size;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &d))
	{
		acl_free(acl);
		acl = NULL;
	}
	size = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (size > 0)
		return ('@');
	if (acl != NULL)
		return ('+');
	return ('\0');
}

void		put_space(int max, char *str, int m)
{
	char	*para;
	char	*max_s;

	max_s = ft_itoa_base(max, 10);
	if (m)
	{
		para = ft_strjoin("%-", max_s);
		para = ft_strjoin_f(para, "s  ", 1, 0);
	}
	else
	{
		para = ft_strjoin("%", max_s);
		para = ft_strjoin_f(para, "s ", 1, 0);
	}
	ft_printf(para, str);
	free(max_s);
	free(para);
}

void		put_mode(struct stat st, char *path)
{
	char	tab[12];

	tab[0] = file_type(st);
	tab[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
	tab[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
	tab[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
	tab[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
	tab[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
	tab[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
	tab[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
	tab[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
	tab[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
	tab[10] = get_acl_xt(path);
	tab[11] = '\0';
	ft_printf("%-12s", tab);
}

void		put_ls_l(t_ls *ls, int i, t_max_ll *max)
{
	char		*path;

	path = ft_strjoin_f(ls->path, "/", 0, 0);
	path = ft_strjoin_f(path, ls->tab[i].d_name, 1, 0);
	get_info(path, max, ls, i);
	free(path);
}
