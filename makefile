# Compiler and flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall -Wextra -g

# Targets
TARGET = mycomp
OBJS = mycomp.o complex.o commands.o

# Build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile mycomp.c
mycomp.o: mycomp.c commands.h complex.h
	$(CC) $(CFLAGS) -c mycomp.c

# Compile commands.c
commands.o: commands.c commands.h complex.h
	$(CC) $(CFLAGS) -c commands.c

# Compile complex.c
complex.o: complex.c complex.h
	$(CC) $(CFLAGS) -c complex.c

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
