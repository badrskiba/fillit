#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 18:16:40 by mhaziza           #+#    #+#              #
#    Updated: 2016/09/21 14:03:08 by lbenamer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC      =   gcc
RM      =   rm -f
CFLAGS  =   -Wall -Wextra -Werror
LIB		=	-L. -lft
NAME    =   fillit
SRCS    =   main.c \
			check.c \
			check2.c \
			param.c\
			map.c\
			solver.c\

OBJS    =   $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean:     clean
	$(RM) $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
