TARGET=fleury.o

CCO=g++
# warnings
WARN=-Wall

CCFLAGS=$(WARN)

SRC= Graph/*.cpp

all:
	$(CCO) -o $(TARGET) $(SRC) main.cpp $(CCFLAGS) -lm -O3

debug:
	$(CCO) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -DDEBUG=1 -O3

run:
	./$(TARGET)

clear:
	rm $(TARGET)