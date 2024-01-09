CC=g++

DEV_CFLAGS=-Wall -g -I./include -std=c++23
PROD_CFLAGS=-Wall -O3 -I./include -std=c++23

LDFLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC_DIR=./src
OBJ_DIR=./obj
BIN_DIR=./bin

SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

TARGET_PROD=./Pong
TARGET_DEV=$(BIN_DIR)/Pong

.PHONY: all dev prod clean

all: dev prod

dev: CFLAGS=$(DEV_CFLAGS)
dev: $(TARGET_DEV)

prod: CFLAGS=$(PROD_CFLAGS)
prod: $(TARGET_PROD)

$(TARGET_PROD): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TARGET_DEV): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET_DEV)
