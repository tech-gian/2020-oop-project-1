# paths


# compiler
CC = g++

# Compile options
CFLAGS = -Wall -Werror

# Files .o
OBJS = main.o classes.o

# Executable file
EXEC = main

# Arguments
ARGS = 3 1 0.3 0.7 < input.txt

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)
