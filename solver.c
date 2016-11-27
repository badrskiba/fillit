
#include "fillit.h"

int		solu_map(t_map *map, t_lst *lst_tetri)
{
	int	x;
	int	y;
	t_lst *tmp;

	tmp = lst_tetri;
	if (lst_tetri == NULL)
		return (1);
	x = 0;
	y = 0;
	while (y <= map->size - lst_tetri->h + 1)
	{
		x = 0;
		while (x <= map->size - lst_tetri->l + 1)
		{
			if(place_if(tmp, map, x, y))
			{
				if(solu_map(map, lst_tetri->next))
					return (1);
			}
			x++;
		}
		y++;
	}
	return(0);
}

int		ft_racine(int n)
{
	int size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

int		ft_lst_count_ele(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_map		*solve(t_lst *lst_tetri)
{
	t_map	*map;
	int		size;

	map = NULL;
	size = ft_racine(ft_lst_count_ele(lst_tetri) * 4);
	map = new_map(size);
	while (solu_map(map, lst_tetri) == 0)
	{
		size++;
	//	free_map(map);
		map = new_map(size);
	}
	return (map);
}
