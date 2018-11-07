# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2018/11/07 20:00:25 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CCFLAGS	=	-Wall -Werror -Wextra -Iincludes

SRCS	=	ft_memmove.c	\
			ft_strlen.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strdup.c		\
			ft_strsub.c		\
			ft_strsplit.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
							\
			ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\
			ft_putendl.c	\
			ft_putendl_fd.c	\
							\
			ft_itoa.c		\

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
