.PHONY: all clean run

all: ./bin/geometry
	
./bin/geometry: ./build/main.o ./build/calcs.o ./build/input-output.o
	gcc -Wall ./build/main.o ./build/calcs.o ./build/input-output.o -o ./bin/geometry/main

./build/main.o: ./src/main.c
	gcc -Wall -c ./src/main.c -o ./build/main.o

./build/calcs.o: ./src/calcs.c
	gcc -Wall -c ./src/calcs.c -o ./build/calcs.o

./build/input-output.o: ./src/input-output.c
	gcc -Wall -c ./src/input-output.c -o ./build/input-output.o


clean:
	rm  ./bin/geometry/main ./build/*.o


