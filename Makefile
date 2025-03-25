SRCS =			 mandelbrot.c julia.c main.c error.c
				
				
				
OBJS =			$(SRCS:.c=.o)

EXE_NAME =		fractol

LIBFT =			./Libft/libft.a

MINXLIB =	./minilibx-linux/libmlx_linux.a

CC =			cc
CFLAGS =		-Wall -Wextra
MLXFLAGS =		-Lminilibx-linux
X =				-lmlx -lX11 -lXext
MATH =			-lm

all:			$(LIBFT) $(EXE_NAME)

$(EXE_NAME):	$(OBJS) $(LIBFT) $(MINXLIB)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(EXE_NAME) $(MLXFLAGS) $(X) $(MATH) -o $@

$(LIBFT):
				make -C ./Libft all

$(MINXLIB):
				make -C ./minilibx-linux all

fclean: clean
				rm -rf $(EXE_NAME)
				make -C ./Libft fclean

clean: 
				rm -rf $(OBJS)
				make -C ./Libft clean

re: fclean all

.PHONY: all fclean clean re