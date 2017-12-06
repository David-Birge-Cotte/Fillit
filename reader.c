/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:12:56 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/28 12:12:56 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static unsigned int	matcher(unsigned int *tetri, unsigned int i)
{
	if (i >= 31)
		return (0);
	if (*tetri >> 31 & 1)
	{
		if (*tetri == TETRI_01A || *tetri == TETRI_01C || *tetri == TETRI_01D
		|| *tetri == TETRI_02A || *tetri == TETRI_02B || *tetri == TETRI_02D
		|| *tetri == TETRI_03A || *tetri == TETRI_03B || *tetri == TETRI_04A
		|| *tetri == TETRI_04B || *tetri == TETRI_05A || *tetri == TETRI_06A
		|| *tetri == TETRI_07B)
			return (1);
		else
			return (0);
	}
	if (*tetri >> 30 & 1)
		if (*tetri == TETRI_02C || *tetri == TETRI_03C || *tetri == TETRI_03D
		|| *tetri == TETRI_06B || *tetri == TETRI_07A)
			return (1);
	if (*tetri >> 29 & 1)
		if (*tetri == TETRI_01B)
			return (1);
	*tetri <<= 1;
	return (matcher(tetri, i + 1));
}

static unsigned int	verif_format(unsigned int *tetri, char *buf, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	*tetri = 0;
	while (i < len)
	{
		while (j < 4)
		{
			if (i < len && buf[i] != '.' && buf[i] != '#')
				return (0);
			*tetri = (*tetri << 1) | (buf[i] == '#' ? 1 : 0);
			i++;
			j++;
		}
		i++;
		j = 0;
	}
	*tetri <<= 16;
	return (1);
}

size_t				reader(unsigned int ***tab, unsigned int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		i;
	size_t	j;

	j = 0;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (buf[0] != '.' && buf[0] != '#')
			return (0);
		if (!((*tab)[j] = (unsigned int *)malloc(sizeof(int) * 2)))
			return (0);
		if (!verif_format(&(*tab)[j][0], buf, ft_strlen(buf)))
			return (0);
		if (!matcher(&(*tab)[j][0], 16))
			return (0);
		if ((i = read(fd, buf, 1)) == -1 || buf[0] == 0)
			return (0);
		j++;
	}
	if (buf[0] == '\n' ||
		!((*tab)[j] = (unsigned int *)malloc(sizeof(int) * 1)))
		return (0);
	(*tab)[j][0] = 0;
	return (j);
}
