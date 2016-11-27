/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:31:14 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/27 04:40:10 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*ft_tetri_param(t_lst *lst)
{
	int i;
	int j;
	int diez;
	int imin = 0;
	int jmin = 0;
	int imax = 0;
	int jmax = 0;
	
	i = 0;
	j = 0;
	diez = 0;
	while(j < 4)
	{
		while(i < 4)
		{
			if(lst->tetri[j][i] == '#')
			{
				diez++;
				if(diez == 1)
				{
					imin = i;
					jmin = j;
				}
				else
				{
					if(i <= imin)
						imin = i;
					if (i >= imax)
						imax = i;
					if(j <= jmin)
						jmin = j;
					if(j >= jmax)
						jmax = j;
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
	lst->h = jmax - jmin + 1;
	lst->l = imax - imin + 1;
	return (lst);
}

t_lst		*ft_lst_putparam(t_lst *lst)
{
	t_lst *tmp;

	tmp = lst;
	while(tmp)
	{
		tmp = ft_tetri_param(tmp);
		tmp = tmp->next;
	}
	return (lst);
}

