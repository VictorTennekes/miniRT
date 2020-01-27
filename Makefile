# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/23 11:18:15 by vtenneke       #+#    #+#                 #
#    Updated: 2020/01/27 13:43:39 by vtenneke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minirt
SRCS			=	main.c\
					error.c
CFILES			=	$(SRCS:%=srcs/%)
OFILES			=	$(CFILES:.c=.o)
CFLAGS			=	-Wall -Wextra -Werror -DNOLIST -Wno-unused-parameter
INCLUDES		=	-I includes\
					-I lib/mlx\
					-I lib/libft/includes\
					-I lib/liblist
LIBS			=	-L lib/mlx -lmlx\
					-L lib/libft -lft\
					-L lib/liblist -llist

# LIB LOCATIONS
MLX_LOC			=	lib/mlx
LIBFT_LOC		=	lib/libft
LIBLIST_LOC		=	lib/liblist

# COLORS
WHITE   = \x1b[37;01m
CYAN    = \x1b[36;01m
PINK    = \x1b[35;01m
BLUE    = \x1b[34;01m
YELLOW  = \x1b[33;01m
GREEN   = \x1b[32;01m
RED     = \x1b[31;01m
BLACK   = \x1b[30;01m
RESET   = \x1b[0m

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(WHITE)/-----		Compiling mlx		-----\\ $(RESET)"
	make -C $(MLX_LOC)
	@echo "$(WHITE)/-----		Compiling libft		-----\\ $(RESET)"
	make bonus -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Compiling liblist	-----\\ $(RESET)"
	make -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Compiling miniRT	-----\\ $(RESET)"
	$(CC) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME) $(OFILES)

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	@echo "$(WHITE)/-----		Cleaning mlx		-----\\ $(RESET)"
	make clean -C $(MLX_LOC)
	@echo "$(WHITE)/-----		Cleaning libft		-----\\ $(RESET)"
	make clean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Cleaning liblist	-----\\ $(RESET)"
	make clean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Cleaning miniRT		-----\\ $(RESET)"
	rm -f $(OFILES)

fclean: clean
	@echo "$(WHITE)/-----		Fcleaning libft		-----\\ $(RESET)"
	make fclean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Fcleaning liblist	-----\\ $(RESET)"
	make fclean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Fcleaning miniRT	-----\\ $(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re