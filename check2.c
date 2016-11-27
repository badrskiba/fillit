/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:31:14 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/25 03:50:10 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isdiez(char c)
{
	if(c == '#')
		return (1);
	return (0);
}

int		ft_check_diez(t_lst *lst, int j, int i)
{
	int tab[4] = {0,0,0,0};
	int check;
	if(i != 3)
		tab[0] = ft_isdiez(lst->tetri[j][i + 1]);
	if(j != 3)
		tab[1] = ft_isdiez(lst->tetri[j+1][i]);
	if(j != 0)
		tab[2] = ft_isdiez(lst->tetri[j-1][i]);
	if(i != 0 )
		tab[3] = ft_isdiez(lst->tetri[j][i - 1]);
	check = tab[0] + tab[1] + tab[2] + tab[3];
	return(check);
}

int		ft_check_tetri(t_lst *lst)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while(j < 4)
	{
		while(i < 4)
		{
			if(lst->tetri[j][i] == '#')
				ret = ret + ft_check_diez(lst, j, i);
			i++;
		}
		i = 0;
		j++;
	}
	if(ret < 6)
		return (0);
	return (1);
}
