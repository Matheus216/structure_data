CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/CircularList.c
OUT = bin/main

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf bin
