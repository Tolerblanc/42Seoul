AR = ar
ARFLAGS = rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a

INCLUDES_DIR = ./includes
INCLUDES = ft.h

SRCS_DIR = ./srcs

SRC = ft_putchar.c \
	ft_swap.c \
	ft_putchar.c \
	ft_strlen.c \
	ft_strcmp.c

OBJS = $(addprefix $(SRCS_DIR)/, $(SRC:.c=.o))

all : $(TARGET)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

$(TARGET) : $(addprefix $(INCLUDES_DIR)/, $(INCLUDES)) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.c.o :
	$(CC) $(CFALGS) -I $(INCLUDES_DIR) -c $< -o $(<:.c=.o)