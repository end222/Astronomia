all: main.cpp
	g++ -std=c++11 main.cpp -o main

clean:
	rm -rf main
	rm -rf .ma*
