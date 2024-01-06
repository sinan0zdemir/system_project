CC = gcc
CFLAGS = -Wall -g

# List of source files
SRC_FILES = goals.c match.c squads.c main.c 
# Generate the corresponding object file names
OBJ_FILES = $(SRC_FILES:.c=.o)

# Name of the executable
EXECUTABLE = program

# Default target, which builds the executable
all: $(EXECUTABLE)

# Rule to build the executable from object files
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile each source file into its object file
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean rule to remove object files and the executable
# Change to {del $(OBJ_FILES) $(EXECUTABLE).exe} on Windows
# Change to {rm -rf $(OBJ_FILES) $(EXECUTABLE)} on UNIX

clean:
	del $(OBJ_FILES) $(EXECUTABLE).exe
