TARGET = ./main.out
HDRS_DIR = project/include

SRCS = \
       project/src/main.c \

.PHONY: all build test clean

all: clean build test

$(TARGET): $(SRCS) 
	$(CC) -Wpedantic -Wall -Wextra -I $(HDRS_DIR) -o $(TARGET) $(SRCS)

build: $(TARGET)

test: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)