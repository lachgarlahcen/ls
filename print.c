/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:51:52 by rel-hada          #+#    #+#             */
/*   Updated: 2019/04/17 02:06:59 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_with_space(char *str, int max_l, int s)
{
	int i;

	i = max_l - ft_strlen(str);
	ft_printf("%s", str);
	if (s)
		while (i > 0)
		{
			ft_printf(" ");
			i--;
		}
}
