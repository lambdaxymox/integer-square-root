CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
CC=gcc
BINARY_ROOT=bin

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

TARGET=$(BINARY_ROOT)/integer_sqrt

$(TARGET): build $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) 

.PHONY: all build clean run

all: $(TARGET)

build:
	mkdir -p bin

clean:
	rm -rf bin

run:
	./$(TARGET)

