
NAME = miniRT

CC = cc
CFLAGS = -Wall -Werror -Wextra -Isrc -Isrc/includes

RM = rm -f

LIBFT_PATH = ./libft
FT_LIBFT = $(LIBFT_PATH)/libft.a

OBJDIR = obj


SRCS = src/minirt.c

OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -g $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): libraries $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_LIBFT) -o $(NAME) 
libraries:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_PATH)
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
