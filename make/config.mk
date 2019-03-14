UNAME_S         :=          $(shell uname)

# Compilation
CC				=			clang

# Paths
SRCDIR			=			./src/
INCDIR			=			./includes/

# Tests
TEST_DIR		=			./tests/
TEST_SRCDIR		=			$(addprefix $(TEST_DIR), src/)
TEST_INCDIR		=			$(addprefix $(TEST_DIR), includes/)

#MLX
MLX_INC			=			/usr/local/include
MLX_ARGS		=			$(shell pkg-config --libs --static mlx) 
ifeq ($(UNAME_S),Darwin)
MLX_ARGS		=			-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
endif

