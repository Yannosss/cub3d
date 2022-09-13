##########   BASE   ##########
# File name
NAME = cub3D

# Sources
SRCS += srcs/main.c
#SRCS += ...

OBJS = ${SRCS:.c=.o}

HEADER += includes/cub3D.h
HEADER += includes/cub3D_julia.h
HEADER += includes/cub3D_yann.h


INCLUDES_DIR= -I ./includes/ -I ./libft/ -I ./minilibx/

LIB_INCLUDE = -L ./libft -lft -L ./minilibx/ -lX11 -lmlx -lXext

# Compilateurs
CC = cc
CFLAGS = -g
#CFLAGS = -Wall -Wextra -Werror -g

##########   RULES   ##########

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft all
	${CC} ${SRCS} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES_DIR)

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
