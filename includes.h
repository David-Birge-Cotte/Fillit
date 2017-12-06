/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 09:46:12 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/30 10:54:33 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "tetriminos.h"
# include "./libft/libft.h"
# define BUFF_SIZE 20

int				create_grid(unsigned int **grid, size_t size);
void			ft_print_final_grid(unsigned int ***tab,
				size_t nb_tetri, size_t size);
size_t			reader(unsigned int ***tab, unsigned int fd);
int				solve(unsigned int ***tab, unsigned int **grid,
				size_t nb_tetri);
void			destroyer_tab(unsigned int **str_tab, size_t size);

#endif
