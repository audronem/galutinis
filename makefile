all: programa

programa: v1.0.o funkcijos.o
	g++ v1.0.o funkcijos.o -o programa

v0.5.o: v1.0.cpp
	g++ -c v1.0.cpp

funkcijos.o: funkcijos.cpp
	g++ -c funkcijos.cpp

clean: rm -rf *.o programa
