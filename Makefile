SRCS = so_long.c mms_func.c utils.c valid.c map.c mlx_func.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
cc = gcc
RM = rm -f

B_SRCS = so_long_bonus.c \
		mms_func_bonus.c \
		utils_bonus.c \
		valid_bonus.c \
		map_bonus.c \
		mlx_func_bonus.c \
		read_img_bonus.c \
		font_bonus.c
B_OBJS = ${B_SRCS:.c=.o}

MLX 	= opengl/libmlx.a
MLX_B_F	= mlx/libmlxb.dylib
MLX_B	= libmlxb.dylib

MCHECK = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
LIBS = -L ./opengl -lmlx -framework OpenGL -framework Appkit
MMS = -L ./mlx -lmlxb -framework OpenGL -framework Appkit
LIBFT = -L ./libft -lft

all : ${NAME}
$(NAME) : ${OBJS} 
	@${MAKE} -C ./libft bonus
	@${MAKE} -C ./mlx 
	@${MAKE} -C ./opengl 
	${CC} ${CFLAGS} ${SRCS} ${LIBS} ${MMS} ${LIBFT} -o ${NAME}
	cp ./${MLX_B_F} ./${MLX_B}
bonus : ${B_OBJS}
	@${MAKE} -C ./libft bonus
	@${MAKE} -C ./mlx 
	@${MAKE} -C ./opengl 
	${CC} ${CFLAGS} ${B_SRCS} ${LIBS} ${MMS} ${LIBFT} -o ${NAME}
	cp ./${MLX_B_F} ./${MLX_B}
.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
clean :
	@${MAKE} -C ./libft clean
	@${MAKE} -C ./mlx clean
	@${MAKE} -C ./opengl clean
	${RM} ${OBJS} ${B_OBJS}
fclean : clean
	@${MAKE} -C ./libft fclean
	${RM} ${NAME} ${B_NAME} ${MLX} ${MLX_B} ${MLX_B_F}
re : fclean all
