NAME := libftprintf.a

LIBFT_DIR := libft

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

SRC_LIBFT_NP = ft_putchar_fd.c \
	       ft_putstr_fd.c  \
	       ft_strchr.c \
	       ft_strlen.c \
	       ft_itoa.c \
	       ft_bzero.c \
	       ft_calloc.c \
	       ft_toupper.c

SRC_LIBFT = $(addprefix $(LIBFT_DIR)/, $(SRC_LIBFT_NP))

OBJ_LIBFT_NP = $(SRC_LIBFT_NP:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

OBJ = $(SRC:.c=.o)

COMPILE := $(CC) $(CFLAGS) 

RANLIB := ranlib $(NAME)

REMOVE := rm -f

all: $(NAME)

$(NAME): $(SRC) $(SRC_OBJ)

	$(COMPILE) $(SRC) -c
	$(COMPILE) $(SRC_LIBFT) -c
	mv $(OBJ_LIBFT_NP) $(LIBFT_DIR)/
	ar rc $(NAME) $(OBJ) $(OBJ_LIBFT)
	$(RANLIB)

clean:
	$(REMOVE) $(OBJ) $(OBJ_LIBFT)

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all
