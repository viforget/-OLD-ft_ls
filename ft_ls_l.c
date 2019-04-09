/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:20:19 by viforget          #+#    #+#             */
/*   Updated: 2019/04/09 02:58:37 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_addright(char *str, unsigned char type)
{
	struct stat stt;
	char right[11];

	stat(str, &stt);
	right[0] = TYPE[type];
}

void	ft_addinfotab(char **tab, size_t ct, unsigned char *type)
{
	int i;
	char right[3];

	right[0] = '.';
	right[1] = ' ';
	right[2] = 0;
	i = 0;
	while (i < ct)
	{
		ft_addright(tab[i], type[i]);
		i++;
	}
}
