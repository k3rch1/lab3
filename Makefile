CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iincludes
TARGET = prog

SOURCES = \
  src/app/main.c \
  src/app/io.c \
  src/app/in_houses.c \
  src/app/out_houses.c \
  src/app/houses_table.c \
  src/app/parse_args.c \
  src/app_modes/generate.c \
  src/container/vector.c \
  src/container/comparator.c \
  src/container/sort.c

OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)