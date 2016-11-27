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

int		ft_check_size(t_lst *lst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(lst->tetri == 0)
		return (0);
		while(lst->tetri[j])
		{
				while(lst->tetri[j][i])
					i++;
				if(i != 4)
					return (0);
				i = 0;
				j++;
		}
		if(j != 4)
			return (0);
	return (1);
}

int		ft_check_char(t_lst *lst)
{
	int j;
	int i;
	int diez;

	i = 0;
	j = 0;
	diez = 0;
		while(lst->tetri[j])
		{
				while(lst->tetri[j][i])
				{
					if(lst->tetri[j][i] == '#')
						diez++;
					if(lst->tetri[j][i] != '.' && lst->tetri[j][i] != '#')
						return (0);
					i++;
				}
				i = 0;
				j++;
		}
		if(diez != 4)
			return (0);
	return (1);
}



int		ft_check_elem(t_lst *lst)
{
	int i;
	i = 0;
	t_lst *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if(i > 26)
		return (0);
	return (1);
}


int		ft_check_final(t_lst *lst)
{
	int check;
	t_lst *tmp;

	tmp = lst;
	while(tmp)
	{
		check = ft_check_char(tmp)  * ft_check_tetri(tmp) * ft_check_size(tmp);
		if(check == 0)
			return (0);
		tmp = tmp->next;
	}
	if(check * ft_check_elem(lst) == 0)
		return (0);
	return (1);
}
