/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:48:00 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/25 03:50:16 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct		f_list
{
	char			**tetri;
	char			name;
	int				h;
	int				l;
	struct f_list	*next;
}					t_lst;

typedef struct		s_map
{
	char			**tab;
	int				size;
}					t_map;

t_lst				*ft_tetri_param(t_lst *lst);
t_lst				*ft_lst_putparam(t_lst *lst);
t_lst				*ft_tetri_new(char *bug, char name);
t_lst				*ft_read(int fd);

t_map				*solve(t_lst *lst_tetri);
t_map				*new_map(int size);

void				ft_print_list(t_lst *list);
void				place(t_lst *lst_tetri, t_map *map,int x, int y,
																	char name);
void				free_map(t_map *map);
void				print_map(t_map *map);


int					ft_check_diez(t_lst *lst, int j, int i);
int					ft_isdiez(char c);
int					ft_countn(char *str);
int					ft_check_size(t_lst *lst);
int					ft_check_char(t_lst *lst);
int					ft_check_tetri(t_lst *lst);
int					ft_check_final(t_lst *lst);
int					ft_check_elem(t_lst *lst);
int					solu_map(t_map *map, t_lst *lst_tetri);
int					ft_racine(int n);
int					place_if(t_lst *lst_tetri, t_map *map,int x, int y);
int					ft_lst_count_ele(t_lst *lst);

#endif
