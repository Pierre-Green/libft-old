include ../../global.mk

NAME	=	io

SRC		=	ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putendl.c	\
			ft_putendl_fd.c	\
			ft_putnbr.c		\
			ft_putnbr_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\

OBJ	= $(SRC:.c=.o)

all: prepare $(OBJ)

prepare:
	@mkdir -p $(ODIR)/$(NAME)

$(OBJ): %.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$(NAME)/$@