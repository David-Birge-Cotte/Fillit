# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 21:21:27 by fbertoia          #+#    #+#              #
#    Updated: 2017/11/30 10:39:35 by dbirge-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = .
SRCS = main.c reader.c solver.c utils.c
LIB_DIR = ./libft 
LIB_NAME = ft
OBJS = $(SRCS:.c=.o)

all: library $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -l$(LIB_NAME) -o $@

library:
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $?

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all
