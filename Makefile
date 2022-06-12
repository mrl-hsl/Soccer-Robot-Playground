CC = g++
CFLAGS  = -g -Wall
RM = rm

OPENCV = `pkg-config --cflags --libs opencv4`

lIBS = $(OPENCV)

all: main

main: main.o Field.o World.o
	$(CC) $(CFLAGS) -o main main.o Field.o World.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(lIBS)

Field.o: Field.cpp
	$(CC) $(CFLAGS) -c Field.cpp $(lIBS)

World.o: World.cpp
	$(CC) $(CFLAGS) -c World.cpp $(lIBS)

# $(TARGET): $(TARGET).c
# 	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm *.o main
