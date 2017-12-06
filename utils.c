/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:12:32 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/28 12:12:34 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void		fill_the_field(unsigned int ***tab, char ***str_tab,
					size_t nb_tetri, size_t size)
{
	size_t i;
	size_t j;
	size_t k;
	size_t x;
	size_t y;

	i = 0;
	while (i < nb_tetri && !(k = 0))
	{
		x = (*tab)[i][1] % size;
		y = (*tab)[i][1] / size;
		while (k < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (((*tab)[i][0] & 0x80000000) != 0)
					(*str_tab)[y + k][x + j] = 'A' + i;
				(*tab)[i][0] <<= 1;
				j++;
			}
			k++;
		}
		i++;
	}
}

static void		destroyer_str(char **str_tab, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		free(str_tab[i]);
		i++;
	}
	free(str_tab);
}

void			destroyer_tab(unsigned int **str_tab, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		free(str_tab[i]);
		i++;
	}
	free(str_tab);
}

int				create_grid(unsigned int **grid, size_t size)
{
	size_t	i;

	i = 0;
	if (!(*grid = (unsigned int *)malloc(sizeof(unsigned int) * (size + 5))))
		return (0);
	while (i < size)
	{
		(*grid)[i] = ~0;
		(*grid)[i] = (*grid)[i] >> size;
		i++;
	}
	(*grid)[i] = ~0;
	(*grid)[i + 1] = ~0;
	(*grid)[i + 2] = ~0;
	(*grid)[i + 3] = ~0;
	(*grid)[i + 4] = ~0;
	return (1);
}

void			ft_print_final_grid(unsigned int ***tab,
				size_t nb_tetri, size_t size)
{
	char	**str_tab;
	size_t	i;

	if (!(str_tab = (char **)malloc(sizeof(char*) * (size + 5))))
		return ;
	i = 0;
	while (i < size + 4)
	{
		if (!(str_tab[i] = ft_strnew(size + 4)))
			return ;
		ft_memset(str_tab[i], (int)'.', size);
		i++;
	}
	str_tab[i] = 0;
	fill_the_field(tab, &str_tab, nb_tetri, size);
	i = 0;
	while (i < size)
	{
		ft_putendl(str_tab[i]);
		i++;
	}
	destroyer_str(str_tab, size + 4);
}
