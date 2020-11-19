# paths
MODULES =
INCLUDE =

# compiler
CC = g++

# Compile options
GXXFLAGS = -Wall -Werror -g

# Files .o
OBJS = main.o classes.o

# Executable file
EXEC = main

# Arguments
ARGS = 3 10 0.3 0.7 < input.txt

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)
