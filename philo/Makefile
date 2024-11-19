# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 03:06:19 by junsepar          #+#    #+#              #
#    Updated: 2023/08/12 18:30:24 by junsepar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEAD = philosopher.h

SRCS = \
act.c \
atoi.c \
init.c \
itoa.c \
main.c \
split.c\
utils.c\
check.c\

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %c
	$(CC) $(CFLAGS) -c $< -o -I $(HEAD)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	
re :
	make fclean
	make all

.PHONY: all clean fclean re
