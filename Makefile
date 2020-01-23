# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/23 11:18:15 by vtenneke       #+#    #+#                 #
#    Updated: 2020/01/23 15:50:51 by vtenneke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minirt
SRCS			=	main.c
CFILES			=	$(SRCS:%=srcs/%)
OFILES			=	$(CFILES:.c=.o)
CFLAGS			=	-Wall -Wextra -Werror

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
	@echo "$(WHITE)/-----		mlx		-----\\ $(RESET)"
	make -C mlx
	@echo "$(WHITE)/-----		libft		-----\\ $(RESET)"
	make -C libft
	@$(CC) -Lmlx -lmlx -Llibft -framework OpenGL -framework AppKit -o $(NAME) $(OFILES)

%.o: %.c
	@printf "$(WHITE)Compiling	$(RESET)$<\n"
	@gcc -Wall -Wextra -Werror -Imlx -Ilibft -c $< -o $@
	
clean:
	@echo "$(WHITE)Cleaning:$(RESET)"
	rm -f $(OFILES)

fclean: clean
	@echo "$(WHITE)Cleaning:$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re