CC = gcc
CFLAGS = -Wextra -Wall -Werror
# -L : 라이브러리 경로 지정
LFLAGS = -L. -lft
MLX = -L ./mlx -lmlx -framework OpenGL -framework Appkit
AR = ar rcs

NAME = so_long

SRC = so_long.c map.c mlx_func.c
OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	make -C libft/ bonus
	cp libft/libft.a ./
	make -C ./mlx
	$(CC) $(CFLAGS) $(LFLAGS) $(MLX) $^ -o $@ 

all: $(NAME)

fclean: clean
	rm -rf $(NAME)
	rm -rf libft.a
	make fclean -C libft/
	make clean -C mlx/

clean:
	rm -rf $(OBJS)
	make clean -C libft/
	make clean -C mlx/

re: fclean all