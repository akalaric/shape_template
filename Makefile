TARGET = shapes
SRC = src/main.cpp
SRC_SCRIPT = run_shapes.sh

all: build test_cli test_int clean

build:
	g++ $(SRC) -o $(TARGET)

run: build
	./$(TARGET)

test_cli: build
	./$(TARGET) circle 5
	./$(TARGET) rectangle 2 4 
	./$(TARGET) triangle 4 2 5

test_int: build
	./$(SRC_SCRIPT)

clean:
	rm -f $(TARGET)

.PHONY: run clean all build
