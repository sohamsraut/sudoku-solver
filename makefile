CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: sudoku run

sudoku:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./sudoku

clean:
	rm sudoku