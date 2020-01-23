# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 11:08:29 by vtenneke       #+#    #+#                 #
#    Updated: 2019/11/11 14:26:25 by vtenneke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRCS		=	ft_atoi ft_isalnum ft_isalpha ft_isascii\
	ft_isdigit ft_isprint ft_memset ft_strchr ft_strlcat ft_strlcpy ft_strlen\
	ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_bzero ft_memcpy\
	ft_memccpy ft_memchr ft_memcmp ft_memmove ft_calloc ft_strdup ft_substr\
	ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd\
	ft_putstr_fd ft_putendl_fd ft_putnbr_fd
B_SRCS		=	ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus\
	ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus\
	ft_lstiter_bonus ft_lstmap_bonus
CFILES		=	$(SRCS:%=srcs/%.c)
OFILES		=	$(CFILES:.c=.o)
BFILES		=	$(B_SRCS:%=b_srcs/%.c)
BOFILES		=	$(BFILES:.c=.o)
INCLUDES	=	./includes
FLAGS		=	-Wall -Werror -Wextra

# COLORS
WHITE	= \x1b[37;01m
CYAN	= \x1b[36;01m
PINK	= \x1b[35;01m
BLUE	= \x1b[34;01m
YELLOW	= \x1b[33;01m
GREEN	= \x1b[32;01m
RED		= \x1b[31;01m
BLACK	= \x1b[30;01m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(YELLOW)Linking the library..."
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "$(GREEN)Done!"

%.o: %.c
	@echo "$(CYAN)Compiling:	$(WHITE)$<"
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean: clean_b
	@echo "$(YELLOW)Cleaning..."
	@echo "$(GREEN)Done cleaning!"

fclean: clean_b
	@echo "$(RED)Full cleaning..."
	@rm -f $(NAME)
	@echo "$(GREEN)Done cleaning!"

clean_b:
	@rm -f $(BOFILES)
	@rm -f $(OFILES)

re: fclean all

bonus: $(OFILES) $(BOFILES)
	@echo "$(YELLOW)Linking the bonusses into the library..."
	@ar rc $(NAME) $(OFILES) $(BOFILES)
	@ranlib $(NAME)
	@echo "$(GREEN)Done!"
