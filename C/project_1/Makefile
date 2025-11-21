CC = gcc
CFLAGS = -I./include
SRC = src/*.c
OUT = src/bin/main

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p bin
	$(CC) -g $(CFLAGS) $(SRC) -o $(OUT)

clean:
		rm -rf bin
