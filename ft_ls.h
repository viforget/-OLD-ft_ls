/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 02:28:18 by viforget          #+#    #+#             */
/*   Updated: 2019/03/23 02:29:15 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	ft_ls(int flag, char *str);
char	*ft_strdeljoinn(char const *s1, char *s2);
