NAME := libftprintf.a

LIBFT_DIR := ../libft

LIBFT := $(LIBFT_DIR)/libft.a

CC := gcc

CFLAGS := -Wall -Werror -Wextra

SRC = 	ft_printf.c \
	format_conv.c \
	ft_strrev.c \
	print_cs.c \
	print_di.c \
	print_p.c \
	print_u.c \
	print_xX.c

OBJ = $(SRC:.c=.o)

COMPILE := $(CC) $(CFLAGS) 

RANLIB := ranlib $(NAME)

REMOVE := rm -f

all: $(NAME)

$(NAME): $(SRC) $(SRC_OBJ)

	$(COMPILE) $(SRC) -c
	ar rc $(NAME) $(OBJ)
	$(RANLIB)

clean:
	$(REMOVE) $(OBJ)

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all
