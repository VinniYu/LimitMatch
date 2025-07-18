# Common flags
LDFLAGS_COMMON = -lGLEW -lGL -lGLU -lglut -lstdc++
CFLAGS_COMMON  = -c -Wall -I./ -O3 -DGL_SILENCE_DEPRECATION

# Compiler
CC      = g++
CFLAGS  = ${CFLAGS_COMMON}
LDFLAGS = ${LDFLAGS_COMMON}

# Executable names
EXECUTABLE = limitMatch

# Source files
SOURCES = main.cpp order/ORDER.cpp event/EVENT.cpp

# Object files
OBJECTS = main.o order/ORDER.o event/EVENT.o

# Default target
all: $(EXECUTABLE)

# Build executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

# Rule to compile .cpp files in subdirs
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)