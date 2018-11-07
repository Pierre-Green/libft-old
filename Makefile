# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2018/11/07 16:24:43 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CCFLAGS	=	-Wall -Werror -Wextra -Iincludes

SRCS	=	ft_strlen.c		\
			ft_strjoin.c	\
							\
			ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\

OBJ		:=	$(addsuffix .o,$(basename $(SRCS)))
NAME	=	libft.a

all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
