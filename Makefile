##########   BASE   ##########
# File name
NAME = cub3D

# Sources
SRCS += srcs/main.c
SRCS += srcs/05_tools/ft_split_with_garbage_collector.c
SRCS += srcs/05_tools/garbage_collector_1.c
SRCS += srcs/05_tools/garbage_collector_2.c
SRCS += srcs/05_tools/get_img_color.c
SRCS += srcs/05_tools/print_color.c
SRCS += srcs/05_tools/print_map.c
SRCS += srcs/05_tools/print_pixel.c
SRCS += srcs/05_tools/print_shape.c
SRCS += srcs/10_initialisation/data_initialisation.c
SRCS += srcs/20_parser/parser.c
SRCS += srcs/20_parser/pars_file.c
SRCS += srcs/20_parser/pars_map.c
SRCS += srcs/20_parser/pars_file_utils_1.c
SRCS += srcs/20_parser/pars_file_utils_2.c
SRCS += srcs/20_parser/pars_map_utils_1.c
SRCS += srcs/20_parser/pars_map_utils_2.c
SRCS += srcs/20_parser/pars_map_utils_3.c
SRCS += srcs/20_parser/pars_errors.c
SRCS += srcs/30_open_textures/open_textures.c
SRCS += srcs/50_init_mlx/init_mlx.c
SRCS += srcs/60_map_2D/draw_2d_map.c
SRCS += srcs/70_raycasting/compute_ray_hit_point.c
SRCS += srcs/70_raycasting/image_generation.c
SRCS += srcs/70_raycasting/ray_generation.c
SRCS += srcs/70_raycasting/wall_ray_impact.c
SRCS += srcs/70_raycasting/print_wall.c
SRCS += srcs/80_events/ft_hit_box.c
SRCS += srcs/80_events/ft_hooks.c
SRCS += srcs/80_events/ft_move_rotate.c
SRCS += srcs/80_events/ft_move_walk.c
SRCS += srcs/90_exit_functions/exit.c
#SRCS += ...

SRCS_BONUS += srcs/main.c
SRCS_BONUS += srcs/05_tools/ft_split_with_garbage_collector.c
SRCS_BONUS += srcs/05_tools/garbage_collector_1.c
SRCS_BONUS += srcs/05_tools/garbage_collector_2.c
SRCS_BONUS += srcs/05_tools/get_img_color.c
SRCS_BONUS += srcs/05_tools/print_color.c
SRCS_BONUS += srcs/05_tools/print_map.c
SRCS_BONUS += srcs/05_tools/print_pixel.c
SRCS_BONUS += srcs/05_tools/print_shape.c
SRCS_BONUS += srcs/10_initialisation/data_initialisation.c
SRCS_BONUS += srcs/20_parser/parser.c
SRCS_BONUS += srcs/20_parser/pars_file.c
SRCS_BONUS += srcs/20_parser/pars_map.c
SRCS_BONUS += srcs/20_parser/pars_file_utils_1.c
SRCS_BONUS += srcs/20_parser/pars_file_utils_2.c
SRCS_BONUS += srcs/20_parser/pars_map_utils_1.c
SRCS_BONUS += srcs/20_parser/pars_map_utils_2.c
SRCS_BONUS += srcs/20_parser/pars_map_utils_3.c
SRCS_BONUS += srcs/20_parser/pars_errors.c
SRCS_BONUS += srcs/30_open_textures/open_textures.c
SRCS_BONUS += srcs/50_init_mlx/init_mlx.c
SRCS_BONUS += srcs/60_map_2D/draw_2d_map.c
SRCS_BONUS += srcs/70_raycasting/compute_ray_hit_point.c
SRCS_BONUS += srcs/70_raycasting/image_generation.c
SRCS_BONUS += srcs/70_raycasting/ray_generation.c
SRCS_BONUS += srcs/70_raycasting/wall_ray_impact.c
SRCS_BONUS += srcs/70_raycasting/print_wall.c
SRCS_BONUS += srcs/80_events/ft_hit_box.c
SRCS_BONUS += srcs/80_events/ft_hooks_bonus.c
SRCS_BONUS += srcs/80_events/ft_move_rotate.c
SRCS_BONUS += srcs/80_events/ft_move_walk.c
SRCS_BONUS += srcs/90_exit_functions/exit.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

HEADER += includes/cub3D.h

INCLUDES_DIR= -I ./includes/ -I ./libft/ -I ./minilibx/

LIB_INCLUDE = -L ./libft -lft -L ./minilibx/ -lX11 -lmlx -lXext -lm

# Compilateurs
CC = cc
#CFLAGS = -g3 -Wall -Wextra
CFLAGS = -Wall -Wextra -Werror -g

##########   RULES   ##########

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft all
	${CC} ${SRCS} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

bonus: $(OBJS_BONUS) $(HEADER)
	make -C ./libft all
	${CC} ${OBJS_BONUS} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
