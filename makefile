all: main.cpp
	gcc -O3 main.cpp -o main

clean:
	rm -rf main
