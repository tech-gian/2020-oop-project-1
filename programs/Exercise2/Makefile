# paths
MODULES = ../../modules
INCLUDE = ../../include
INPUT   = ../../input

# compiler
CC = g++

# Compile options
CXXFLAGS = -Wall -Werror -g -I$(INCLUDE)

# Files .o
OBJS = main.o $(MODULES)/Sequence.o

# Executable file
EXEC = main

# Arguments
ARGS = 3 10 0.3 0.7 < $(INPUT)/input_ex2.txt

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)
