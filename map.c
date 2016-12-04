
#include "fillit.h"

t_map	*new_map(int size)
{
	int i;
	int j;
	t_map *map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->tab = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	j = 0;
	while (j < size)
	{
		map->tab[j] = ft_strnew(size);
		i = 0;
		while(i < size)
		{
			map->tab[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

void	place(t_lst *lst_tetri, t_map *map, int x, int y, char name)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	printf("\n%c\n",lst_tetri->name);
	while (j < lst_tetri->h)
	{
		i = 0;
		while (i < lst_tetri->l)
		{
			if(lst_tetri->tetri[j][i] == '#')
			{
		//		printf("\n%c\n",lst_tetri->tetri[j][i]);
				map->tab[y + j][x + i] = name;
			}
			i++;
		//	printf("i :%d",i);
		}
		j++;
	}
}

void	free_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->size)
	{
		i = 0;
		while (i < map->size)
		{
		//	ft_memdel((void**)&(map->tab[j][i]));
			i++;
		}
		j++;
	}
//	ft_memdel((void**)&(map->tab));
//	ft_memdel((void**)&map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		place_if(t_lst *lst_tetri, t_map *map,int x, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(j < lst_tetri->h)
	{
		i = 0;
		while(i < lst_tetri->l)
		{
			if (lst_tetri->tetri[j][i] == '#' && map->tab[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
//	printf("\n%c\n",lst_tetri->name);
	place(lst_tetri, map, x, y, lst_tetri->name);
	return (1);
}
