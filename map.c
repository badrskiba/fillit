
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
	while (lst_tetri->tetri[j])
	{
		i = 0;
		while (lst_tetri->tetri[j][i])
		{
			if( lst_tetri->tetri[j][i] == '#') //&& map->tab[y][x] == '.')
			{
				map->tab[y + j][x + i] = name;
			}
			i++;
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
	while (map->tab[j])
	{
		i = 0;
		while (map ->tab[j][i])
		{
			map->tab[j][i] = '.';
			i++;
		}
		j++;
	}
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
	while(j < map->size)
	{
		i = 0;
		while(i < map->size)
		{
			if (lst_tetri->tetri[j][i] == '#' && map->tab[y][x] != '.')
			{
	//			printf("%d",909);
				return (0);
			}
			i++;
		}
		j++;
	}
	place(lst_tetri, map, x, y, lst_tetri->name);
	return (1);
}
