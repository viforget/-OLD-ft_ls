/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:20:19 by viforget          #+#    #+#             */
/*   Updated: 2019/04/12 03:38:34 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_addright(char **str, unsigned char type)
{
	struct stat stt;
	char right[13];

	stat(*str, &stt);
	right[0] = TYPE[type];
	stt.st_mode % 2 == 1 ? right[9] = 'x' : (right[9] = '-');
	stt.st_mode % 4 >= 2 ? right[8] = 'w' : (right[8] = '-');
	stt.st_mode % 8 >= 4 ? right[7] = 'r' : (right[7] = '-');
	stt.st_mode % 16 >= 8 ? right[6] = 'x' : (right[6] = '-');
	stt.st_mode % 32 >= 16 ? right[5] = 'w' : (right[5] = '-');
	stt.st_mode % 64 >= 32 ? right[4] = 'r' : (right[4] = '-');
	stt.st_mode % 128 >= 64 ? right[3] = 'x' : (right[3] = '-');
	stt.st_mode % 256 >= 128 ? right[2] = 'w' : (right[2] = '-');
	stt.st_mode % 512 >= 256 ? right[1] = 'r' : (right[1] = '-');
	right[10] = ' ';
	right[11] = ' ';
	*str = ft_strjoin(right, *str); //END
}

void	ft_addinfotab(char **tab, size_t ct, unsigned char *type)
{
	int i;

	i = 0;
	while (i < ct)
	{
		ft_addright(&tab[i], type[i]);
		i++;
	}
	//ft_puttab(tab, ct);
}
