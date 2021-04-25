all: programa

programa: v0.5.o funkcijos.o
	g++ v0.5.o funkcijos.o -o programa

v0.5.o: v0.5.cpp
	g++ -c v0.5.cpp

funkcijos.o: funkcijos.cpp
	g++ -c funkcijos.cpp

clean: rm -rf *.o programa
