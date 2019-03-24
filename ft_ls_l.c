/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:20:19 by viforget          #+#    #+#             */
/*   Updated: 2019/03/24 15:17:41 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_setrights(char *chmod, char *str)
{
	struct stat buf;

	stat(str, &buf);

}

void	ft_addinfotab(char **tab, size_t ct)
{
	char	chmod[11];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while(j < ct)
	{
		while(i < 11)
		{
			ft_setrights(chmod, tab[j]);
		}
		j++;
	}
}
