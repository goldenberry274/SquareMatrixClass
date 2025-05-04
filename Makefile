CC = g++
FLAGS = -g 

SRC_FILES = Main.cpp SquareMat.cpp
OBJECT_FILES = Main.o SquareMat.o
TST_SRC = Test.cpp
TST_OBJ = Test.o
TST_TARGET = Test
TARGET = Main

all: $(TARGET) $(TST_TARGET)

%.o: %.cpp
	$(CC) -c -o $@ $< $(FLAGS)

$(TARGET): $(OBJECT_FILES)
	$(CC) -o $(TARGET) $(OBJECT_FILES) $(FLAGS)

$(TST_TARGET): $(TST_OBJ)
	$(CC) -o $(TST_TARGET) $(TST_OBJ) $(FLAGS)

run-main: $(TARGET)
	./$(TARGET)

test: $(TST_TARGET)
	./$(TST_TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

.PHONY: clean run-main test valgrind

clean:
	-rm $(OBJECT_FILES) $(TST_OBJ) $(TARGET) $(TST_TARGET)
