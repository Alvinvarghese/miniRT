
NAME = miniRT

CC = cc
CFLAGS = -Wall -Werror -Wextra -Isrc -Isrc/includes -I$(MLX_PATH)

RM = rm -f

LIBFT_PATH = ./libft
FT_LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a

OBJDIR = obj

SRCS =	src/minirt.c \

		src/color_opn_canvas.c \
		src/colour_operations_1.c \

		src/freeup_memory.c \

		src/tuple_operations_1.c \
		src/tuple_operations_2.c\
		
		src/create_ray.c \

		src/matrix_transformations/mtrx_trnsfrm_opn.c \
		src/matrix_transformations/mtrx_trnsfrm_opn1.c \
		src/matrix_transformations/mtrx_trnsfrm_rotation.c \

		src/matrices/matrix_operations.c \
		src/matrices/matrix_operations1.c \
		src/matrices/matrix_determinant.c \

		src/Light_and_Shading/light_n_shading_operations.c \


OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -g $(CFLAGS) -c $< -o $@

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
	clear

re: fclean all

debug: CFLAGS += -g
debug: re
	gdb ./$(NAME)

run: re 
	clear
	./$(NAME)

.PHONY: all libraries clean fclean re debug
