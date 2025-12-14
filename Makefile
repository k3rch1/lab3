CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = prog
SOURCES = app/main.c src/container/vector.c src/container/comparator.c src/container/sort.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)