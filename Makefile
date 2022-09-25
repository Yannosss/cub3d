##########   BASE   ##########
# File name
NAME = cub3D

# Sources
SRCS += srcs/main.c
SRCS += srcs/05_tools/garbage_collector_1.c
SRCS += srcs/05_tools/garbage_collector_2.c
SRCS += srcs/05_tools/get_img_color.c
SRCS += srcs/05_tools/print_color.c
SRCS += srcs/05_tools/print_map.c
SRCS += srcs/05_tools/print_pixel.c
SRCS += srcs/05_tools/print_shape.c
SRCS += srcs/10_initialisation/data_initialisation.c
SRCS += srcs/20_parser/parser.c
SRCS += srcs/20_parser/parsing_file.c
SRCS += srcs/20_parser/parsing_map.c
SRCS += srcs/20_parser/parsing_utils.c
SRCS += srcs/20_parser/parsing_errors.c
SRCS += srcs/50_init_mlx/init_mlx.c
SRCS += srcs/60_map_2D/draw_2d_map.c
SRCS += srcs/70_raycasting/dda_algo.c
SRCS += srcs/70_raycasting/image_generation.c
SRCS += srcs/70_raycasting/ray_generation.c
SRCS += srcs/70_raycasting/wall_ray_impact.c
SRCS += srcs/70_raycasting/print_wall.c
SRCS += srcs/90_exit_functions/exit.c
#SRCS += ...

OBJS = ${SRCS:.c=.o}

HEADER += includes/cub3D.h
HEADER += includes/cub3D_julia.h
HEADER += includes/cub3D_yann.h


INCLUDES_DIR= -I ./includes/ -I ./libft/ -I ./minilibx/

LIB_INCLUDE = -L ./libft -lft -L ./minilibx/ -lX11 -lmlx -lXext -lm

# Compilateurs
CC = cc
CFLAGS = -g3 -Wall -Wextra
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

YANNCOMPILE += srcs/main_yann.c
YANNCOMPILE += srcs/05_tools/garbage_collector_1.c
YANNCOMPILE += srcs/05_tools/garbage_collector_2.c
YANNCOMPILE += srcs/05_tools/get_img_color.c
YANNCOMPILE += srcs/05_tools/print_color.c
YANNCOMPILE += srcs/05_tools/print_map.c
YANNCOMPILE += srcs/05_tools/print_pixel.c
YANNCOMPILE += srcs/05_tools/print_shape.c
YANNCOMPILE += srcs/10_initialisation/data_initialisation.c
#YANNCOMPILE += srcs/20_parser/parser.c
#YANNCOMPILE += srcs/20_parser/parsing_map.c
#YANNCOMPILE += srcs/20_parser/parsing_file.c
#YANNCOMPILE += srcs/20_parser/parsing_utils.c
#YANNCOMPILE += srcs/20_parser/parsing_errors.c
YANNCOMPILE += srcs/30_open_textures/open_textures.c
YANNCOMPILE += srcs/50_init_mlx/init_mlx.c
YANNCOMPILE += srcs/60_map_2D/draw_2d_map.c
YANNCOMPILE += srcs/70_raycasting/dda_algo.c
YANNCOMPILE += srcs/70_raycasting/image_generation.c
YANNCOMPILE += srcs/70_raycasting/print_wall.c
YANNCOMPILE += srcs/70_raycasting/ray_generation.c
YANNCOMPILE += srcs/70_raycasting/wall_ray_impact.c
YANNCOMPILE += srcs/90_exit_functions/exit.c


JULIACOMPILE += srcs/main_julia.c
JULIACOMPILE += srcs/05_tools/garbage_collector_1.c
JULIACOMPILE += srcs/05_tools/garbage_collector_2.c
JULIACOMPILE += srcs/05_tools/print_color.c
JULIACOMPILE += srcs/05_tools/print_map.c
JULIACOMPILE += srcs/20_parser/parser.c
JULIACOMPILE += srcs/20_parser/parsing_file.c
JULIACOMPILE += srcs/20_parser/parsing_map.c
JULIACOMPILE += srcs/20_parser/parsing_utils.c
JULIACOMPILE += srcs/20_parser/parsing_errors.c
JULIACOMPILE += srcs/90_exit_functions/exit.c


yann: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${YANNCOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

julia: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${JULIACOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}
