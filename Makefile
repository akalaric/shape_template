TARGET = shapes
SRC = src/main.cpp

all: run clean

run:
	g++ $(SRC) -o $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean all
