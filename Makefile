CC = gcc
CFLAGS = -fsanitize=address -Wall
SRCS = main.c History.c Display.c Echo.c pwd.c cd.c
OBJS = $(SRCS:.c=.o)
EXEC = shell
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(EXEC)