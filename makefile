TARGET=fleury.o

CCO=g++
WARN=-Wall

CCFLAGS=$(WARN)

SRC= Graph/*.cpp

all:
	$(CCO) -o $(TARGET) $(SRC) main.cpp $(CCFLAGS) -lm -O3

run:
	./$(TARGET)

clear:
	rm $(TARGET)