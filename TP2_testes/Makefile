CC=g++
CFLAGS = -Wall

all: ./bin/tp2

./obj/Heap.o : ./src/Heap.cpp
	${CC} -c ./src/Heap.cpp -o ./obj/Heap.o
	 
./obj/main.o : ./src/main.cpp
	${CC} -c ./src/main.cpp -o ./obj/main.o

./obj/Point.o : ./src/Point.cpp
	${CC} -c ./src/Point.cpp -o ./obj/Point.o

./obj/GraphAdj.o : ./src/GraphAdj.cpp
	${CC} -c ./src/GraphAdj.cpp -o ./obj/GraphAdj.o

./obj/GraphMatrix.o : ./src/GraphMatrix.cpp
	${CC} -c ./src/GraphMatrix.cpp -o ./obj/GraphMatrix.o

./bin/tp2: ./obj/main.o ./obj/Heap.o ./obj/GraphMatrix.o ./obj/GraphAdj.o ./obj/Point.o
	${CC} ./obj/main.o ./obj/GraphAdj.o ./obj/GraphMatrix.o ./obj/Point.o -o ./bin/tp2.out