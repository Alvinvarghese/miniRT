NAME = miniRT

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -I$(MLX_PATH)
RM = rm -f

LIBFT_PATH = ./libft
FT_LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a

OBJDIR = obj

SRCS =	src/main.c \
	src/free/freeup_memory.c \
	src/lights_and_colors/color_opn_canvas.c\
	src/lights_and_colors/colour_operations_1.c\
	src/lights_and_colors/light_n_shading_operations.c\
	src/lights_and_colors/phong_reflection_model.c\
	src/matrix/matrix_determinant.c\
	src/matrix/matrix_operations_1.c\
	src/matrix/matrix_operations.c\
	src/matrix_tranformation/mtrx_trnsfm_opn1.c\
	src/matrix_tranformation/mtrx_trnsfrm_opn.c\
	src/matrix_tranformation/mtrx_trnsfrm_rotation.c\
	src/ray/create_ray.c\
	src/ray/intersecting_rays_with_spheres.c\
	src/rendering/ft_rendering.c\
	src/rendering/setup_mlx.c\
	src/tuple_operations/tuple_operations_1.c\
	src/tuple_operations/tuple_operations_2.c\
	
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	

all: $(NAME)

$(NAME): libraries $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_LIBFT) $(MLX_LIB) -lm -lX11 -lXext -o $(NAME)

libraries:
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(MLX_PATH)
	rm -rf $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

debug: CFLAGS += -g
debug: re
	gdb ./$(NAME)

run: re
	./$(NAME)

.PHONY: all libraries clean fclean re debug run
