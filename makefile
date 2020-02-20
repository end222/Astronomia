all: main.cpp
	g++ -O3 main.cpp -o main

clean:
	rm -rf main
	rm -rf .ma*
