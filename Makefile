NAME := libftprintf.a

LIBFT_DIR := libft

BONUS_DIR := bonus

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

SRC_BONUS_NP =	format_conv_bonus.c \
		ft_printf_bonus.c \
		ft_printf_bonus.h \
		ft_strrev_bonus.c \
		print_cs_bonus.c \
		print_di_bonus.c \
		print_p_bonus.c \
		print_u_bonus.c \
		print_xX_bonus.c

SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(SRC_BONUS_NP))

SRC_LIBFT = $(addprefix $(LIBFT_DIR)/, $(SRC_LIBFT_NP))

OBJ_LIBFT_NP = $(SRC_LIBFT_NP:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

OBJ_BONUS_NP = $(SRC_BONUS_NP:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

COMPILE := $(CC) $(CFLAGS) 

RANLIB := ranlib $(NAME)

REMOVE := rm -f

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(SRC_LIBFT) $(OBJ_LIBFT)

	$(COMPILE) $(SRC) -c
	$(COMPILE) $(SRC_LIBFT) -c
	mv $(OBJ_LIBFT_NP) $(LIBFT_DIR)/
	ar rc $(NAME) $(OBJ) $(OBJ_LIBFT)
	$(RANLIB)

bonus : $(SRC_BONUS) $(OBJ_BONUS) $(SRC_LIBFT) $(OBJ_LIBFT)

	$(COMPILE) $(SRC_BONUS) -c
	$(COMPILE) $(SRC_LIBFT) -c
	mv $(OBJ_LIBFT_NP) $(LIBFT_DIR)/
	mv $(OBJ_BONUS_NP) $(BONUS_DIR)/
	ar rc $(NAME) $(OBJ_BONUS) $(OBJ_LIBFT)
	$(RANLIB)

clean:
	$(REMOVE) $(OBJ) $(OBJ_LIBFT)
	$(REMOVE) $(OBJ_BONUS) $(OBJ_LIBFT)

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all
