include ../../global.mk

NAME	=	io

SRC		=	ft_putchar.c			\
			ft_putchar_fd.c			\
			ft_putendl.c			\
			ft_putendl_fd.c			\
			ft_putnbr.c				\
			ft_putnbr_fd.c			\
			ft_putstr.c				\
			ft_putstr_fd.c			\
									\
			get_next_line.c			\
									\
			ft_printf/ft_printf.c 	\

OBJ	= $(SRC:.c=.o)
vODIR = $(addsuffix /$(NAME), $(ODIR))

all: prepare $(addprefix $(vODIR)/, $(OBJ))

prepare:
	@mkdir -p $(vODIR)/ft_printf

$(vODIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(vODIR)/$@