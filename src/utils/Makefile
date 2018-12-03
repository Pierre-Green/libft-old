include ../../global.mk

NAME	=	utils

SRC		=	ft_atoi.c		\
			ft_divmod.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_tolower.c	\
			ft_toupper.c	\

OBJ	= $(SRC:.c=.o)

all: prepare $(OBJ)

prepare:
	@mkdir -p $(ODIR)/$(NAME)

$(OBJ): %.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$(NAME)/$@