NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libs/libft/libft.a
LIBFT_DIR = libs/libft
MLX_DIR = ./mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
INCLUDES = -I./libs/libft -I./mlx -I./src -I/usr/include

# Lista de arquivos fonte
SRCS = src/check_map_1.c \
       src/check_map_2.c \
       src/check_map_3.c \
       src/checker.c \
       src/render_images.c \
       src/so_long.c \
       src/game_init.c \
       src/keys_handler.c \
       src/free_memory.c

# Transformando src/arquivo.c -> obj/arquivo.o
OBJS = $(SRCS:src/%.c=obj/%.o)

# Regra principal
all: $(MLX_LIB) $(LIBFT) $(NAME)

# Compila o executável
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

# Cria a lib mlx
$(MLX_LIB):
	@make -C $(MLX_DIR)

# Cria a libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Garante que a pasta obj/ existe antes de compilar
obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Cria a pasta obj/ se não existir
obj:
	mkdir -p obj

# Limpeza dos objetos
clean:
	$(RM) obj
	$(MAKE) clean -C $(LIBFT_DIR)

# Limpeza total (objetos + binário)
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Recompilar tudo
re: fclean all
