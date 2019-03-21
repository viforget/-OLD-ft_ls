/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 00:45:05 by viforget          #+#    #+#             */
/*   Updated: 2018/12/07 03:07:22 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab, size_t n)
{
	size_t x;
	size_t y;

	if (!(tab) || !(*tab) || n == 0)
		return ;
	x = 0;
	while (x < n)
	{
		y = 0;
		while (tab[x][y])
		{
			ft_putchar(tab[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
