# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/05 13:53:29 by vtenneke      #+#    #+#                  #
#    Updated: 2020/02/05 13:53:30 by vtenneke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME			=	liblist.a

SRCS			=	foreach\
					new\
					new_back\
					new_front\
					remove\
					reverse\
					size

CFILES			=	$(SRCS:%=lst_%.c)
OFILES			=	$(SRCS:%=lst_%.o)

FLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
