all: main.cpp spin.o
	g++ main.cpp -c -std=c++17 -O3 -Wall -Werror -fno-omit-frame-pointer -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -lpfm
	g++ main.o spin.o -o a.out -std=c++17 -O3 -Wall -Werror -fno-omit-frame-pointer -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -lpfm

spin.o: spin.S
	as spin.S -o spin.o

clean:
	rm *.o *.out
