/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:00:57 by rel-hada          #+#    #+#             */
/*   Updated: 2019/04/19 21:17:36 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define PATH_MAX	4096
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include <sys/ioctl.h>
# include "ft_printf/ft_printf.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct		s_flag
{
	int		flag_presence;
	int		l;
	int		r1;
	int		a;
	int		r;
	int		t;
	int		one;
}					t_flag;
typedef struct		s_max_ll
{
	int		lnk;
	int		size;
	int		usr;
	int		grp;
	int		major;
	int		minor;
}					t_max_ll;

typedef	struct		s_arg
{
	char				*name;
	struct s_arg		*next;
}					t_arg;
typedef	struct		s_error
{
	int		code;
	char	*errostr;
}					t_error;
typedef struct		s_free_tab
{
	struct dirent		*tab;
	struct s_free_tab	*n;
}					t_free_tab;
typedef struct		s_free_char
{
	char				*str;
	struct s_free_char	*n;
}					t_free_char;
typedef	struct		s_ls
{
	t_flag				flags;
	DIR					*dir;
	DIR					*r1;
	struct dirent		*sd;
	char				*path;
	struct winsize		win_max;
	int					col_numb;
	int					cunt;
	int					total;
	struct dirent		*tab;
	struct s_error		*error;
	t_arg				*arg;
	t_arg				*f_r;
	struct s_free_tab	*tabs;
	struct s_free_char	*chars;
}					t_ls;

float				next_8(float max);
int					ls_normal(t_ls *ls, t_free_tab **tabs);
int					ls_l(t_ls *ls, t_free_tab **tabs);
int					max_len(t_ls *ls, int *cunt);
int					rnd(int a, int c);
struct dirent		*ascii_order(struct dirent *tab, int len);
struct dirent		*stock_directories(t_ls *ls, int dir_nums,
		t_free_tab **tabs);
void				print_with_space(char *str, int max_l, int s);
void				ls_r(t_ls ls, t_free_tab **tabs, t_free_char **chars);
void				ls_t(t_ls ls, struct dirent *tab, int len);
void				ft_reverse(t_ls *ls, int cunt);
char				file_type(struct stat st);
void				print_arg(t_ls *ls);
t_max_ll			*comp_max(struct stat st, t_max_ll *max);
void				put_mode(struct stat st, char *path);
void				put_space(int max, char *str, int m);
void				get_size(struct stat st, int max, int major);
void				get_time(time_t t);
void				get_link_path(char *path);
t_arg				*reverse(t_arg *arg);
t_arg				*sort_arg_time(t_arg *arg);
t_max_ll			*get_max_arg(t_ls *ls);
void				ft_reverse(t_ls *ls, int cunt);
void				collect_arg(t_ls *ls, char **argv, int i, int last_arg);
int					collect(int argc, char **argv, t_ls *ls);
void				add_to_list(int *a, t_arg **arg, char *str);
int					exist_err(char *file);
int					exists (char *filename, struct stat *buffer);
void				show_files_errors(t_ls *ls);
void				dell_node(t_arg **arg, char *key);
float				opt(float max_l, t_ls *ls, int *cunt, t_free_tab **tabs);
t_arg				*create_arg(char *str);
t_arg				*sort_arg(t_arg *arg);
int					six_month(time_t t);
t_max_ll			*get_max(t_ls *ls, int cunt);
char				get_acl_xt(char *path);
void				put_space(int max, char *str, int m);
void				put_mode(struct stat st, char *path);
void				get_info(char *file, t_max_ll *max, t_ls *ls, int i);
void				put_ls_l(t_ls *ls, int i, t_max_ll *max);
t_free_tab			*add_to_tabs(t_free_tab **tabs, struct dirent *tab);
void				free_aloc_tabs(t_ls *ls);
t_free_char			*add_to_chars(t_free_char **chars, char *str);
void				free_aloc_chars(t_ls	*ls);

#endif
