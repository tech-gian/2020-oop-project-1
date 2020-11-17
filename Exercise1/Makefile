# paths


# compiler
CC = g++

# Compile options
CFLAGS = -Wall -Werror -g

# Files .o
OBJS = main.o classes.o

# Executable file
EXEC = main

# Arguments
ARGS = 2 5 5 5 < input.txt

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)
