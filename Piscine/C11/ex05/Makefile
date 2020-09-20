CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
		ft_putnbr.c \
		ft_atoi.c \
		operations.c 
OBJS = $(SRCS:.c=.o)

TARGET = do-op

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(TARGET)

.c.o :
		$(CC) $(CFLAGS) -c -o $(<:.c=.o) $<

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(TARGET)

re : fclean all