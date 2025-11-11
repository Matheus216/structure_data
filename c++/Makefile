CC= g++
CFLAGS = -I./include
SRC = src/*.cpp
OUT = bin/main

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p bin 
	$(CC) -g $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf bin