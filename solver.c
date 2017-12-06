/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:01:01 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/28 14:01:01 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int		condition(unsigned int tetri,
				unsigned int *grid, size_t len, size_t pos)
{
	size_t			x;
	size_t			y;
	size_t			i;
	unsigned int	tmp;

	x = pos % len;
	y = pos / len;
	i = 0;
	tmp = tetri;
	while (i < 4)
	{
		tmp >>= (16 + (3 - i) * 4);
		tmp <<= (16 + (3 - i) * 4);
		tmp <<= (4 * i);
		tmp >>= x;
		if (tmp & grid[y])
			return (0);
		y++;
		i++;
		tmp = tetri;
	}
	return (1);
}

static void		putit(unsigned int tetri, unsigned int **grid,
				size_t len, size_t pos)
{
	size_t			x;
	size_t			y;
	size_t			i;
	unsigned int	tmp;

	x = pos % len;
	y = pos / len;
	i = 0;
	tmp = tetri;
	while (i < 4)
	{
		tmp >>= (16 + (3 - i) * 4);
		tmp <<= (16 + (3 - i) * 4);
		tmp <<= (4 * i);
		tmp >>= x;
		(*grid)[y] |= tmp;
		y++;
		i++;
		tmp = tetri;
	}
}

static void		unfillit(unsigned int tetri, unsigned int **grid,
				size_t len, size_t pos)
{
	size_t			x;
	size_t			y;
	size_t			i;
	unsigned int	tmp;

	x = pos % len;
	y = pos / len;
	i = 0;
	tmp = tetri;
	while (i < 4)
	{
		tmp >>= (16 + (3 - i) * 4);
		tmp <<= (16 + (3 - i) * 4);
		tmp <<= (4 * i);
		tmp >>= x;
		(*grid)[y] ^= tmp;
		y++;
		i++;
		tmp = tetri;
	}
}

int				fillit(unsigned int ***tab, unsigned int **grid,
				size_t index, size_t len)
{
	size_t			pos;

	pos = 0;
	if (!(*tab)[index][0])
		return (1);
	while (pos < (len * len))
	{
		if (condition((*tab)[index][0], *grid, len, pos))
		{
			putit((*tab)[index][0], grid, len, pos);
			(*tab)[index][1] = pos;
			if (fillit(tab, grid, index + 1, len))
				return (1);
			unfillit((*tab)[index][0], grid, len, pos);
			(*tab)[index][1] = 0;
		}
		pos++;
	}
	return (0);
}

int				solve(unsigned int ***tab, unsigned int **grid, size_t nb_tetri)
{
	size_t			size;

	size = 0;
	while (size * size < nb_tetri * 4)
		size++;
	create_grid(grid, size);
	while (grid && *grid && !(fillit(tab, grid, 0, size)))
	{
		free(*grid);
		size++;
		if (!(create_grid(grid, size)))
			return (0);
	}
	return (size);
}
