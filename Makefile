TARGET = ./main.out
HDRS_DIR = project/include

SRCS = \
       project/src/main.c \
	   project/src/algorithm.c \
	   project/src/initMatrix.c \
	   project/src/errorChecking.c 

.PHONY: all build clean test

all: clean build

$(TARGET): $(SRCS) 
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(SRCS)

build: $(TARGET)

test: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)