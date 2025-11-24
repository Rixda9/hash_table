CC = gcc
CFLAGS = -Wall -Wextra -g
EXEC = test
SOURCES = hash_table.c test.c

all: $(EXEC)

$(EXEC): $(SOURCES:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXEC) *.o
