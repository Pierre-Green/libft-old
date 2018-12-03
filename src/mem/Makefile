include ../../global.mk

NAME	=	mem

SRC		=	ft_bzero.c		\
			ft_memalloc.c	\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memdel.c		\
			ft_memmove.c	\
			ft_memset.c		\


OBJ	= $(SRC:.c=.o)

all: prepare $(OBJ)

prepare:
	@mkdir -p $(ODIR)/$(NAME)

$(OBJ): %.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$(NAME)/$@