/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:11:52 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/27 06:06:06 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_countn(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			++n;
		i++;
	}
	return (n);
}

t_lst		*ft_read(int fd)
{
	char	*buf;
	t_lst	*lst_tetri;
	int		r;
	t_lst *tmp;

	buf = ft_strnew(21);
	if(!(lst_tetri = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	tmp = lst_tetri;
	r = read(fd, buf, 20);
	if(buf[0] == '\n' || buf[0] == 0)
		return (NULL);
	lst_tetri->tetri = ft_strsplit(buf, '\n');
	lst_tetri->name = 'A';
	lst_tetri->next = NULL;
	while ((r = read(fd, buf, 21)) != 0)
	{
		if(ft_countn(buf) != 5)
			return (NULL);
		if(buf[1] == '\n')
			return (NULL);
		lst_tetri->next = ft_tetri_new(buf, lst_tetri->name + 1);
		lst_tetri = lst_tetri->next;
		buf = ft_strnew(21);
	}
	return (tmp);
}




t_lst		*ft_tetri_new(char *buf, char name)
{
	t_lst *new_tetri;

	new_tetri = NULL;
	if (!buf)
		new_tetri->tetri = (NULL);
	
	else
	{
		if(!(new_tetri = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
		new_tetri->tetri = ft_strsplit(buf, '\n');
		new_tetri->name = name;
		new_tetri->next = (NULL);
	}
	return(new_tetri);
}


void	ft_print_list(t_lst *list)
{
	while(list)
	{
//		ft_putchar(list->name);
		ft_putchar('\n');
		ft_printstab(list->tetri);
		ft_putchar('\n');
		ft_putstr("hauteur = ");
		ft_putnbr(list->h);
		ft_putchar('\n');
		ft_putstr("longueur = ");
		ft_putnbr(list->l);
		ft_putchar('\n');
		list = list->next;
	}
}

int		main(int ac, char **av)
{
	int fd;
	int check;
	t_map *map;
	t_lst	*lst_tetri;

	lst_tetri = NULL;

	if(ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if(fd != -1)
		{
			lst_tetri = ft_read(fd);
			if(!lst_tetri )
			{
				ft_putstr("error\n");
				return 0;
			}
			check = ft_check_final(lst_tetri);
			if(check == 0)
				ft_putstr("error\n");
			else
			{
				ft_lst_putparam(lst_tetri);
				ft_print_list(lst_tetri);
				write(1, "\n", 1);
			}
		}
	}
	map = solve(lst_tetri);
//	print_map(map);
	return 0;
}
