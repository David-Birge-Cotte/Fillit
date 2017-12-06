/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 09:45:26 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/12/04 11:46:33 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	return_error(void)
{
	ft_putendl("error");
	return (1);
}

int			main(int argc, char **argv)
{
	int				fd;
	unsigned int	**tab;
	unsigned int	*grid;
	size_t			nb_tetri;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (return_error());
	if (!(tab = (unsigned int **)malloc(sizeof(unsigned int *) * 27)))
		return (return_error());
	if (!(nb_tetri = reader(&tab, fd)))
		return (return_error());
	ft_print_final_grid(&tab, nb_tetri, solve(&tab, &grid, nb_tetri));
	destroyer_tab(tab, nb_tetri + 1);
	free(grid);
	close(fd);
	return (0);
}
