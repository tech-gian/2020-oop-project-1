# paths
MODULES = ../../modules
INCLUDE = ../../include
INPUT   = ../../input

# compiler
CC = g++

# Compile options
CXXFLAGS = -Wall -Werror -g -I$(INCLUDE)

# Files .o
OBJS = main.o $(MODULES)/School.o

# Executable file
EXEC = main

# Arguments
ARGS = 2 5 5 5 < $(INPUT)/input_ex1.txt

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)
