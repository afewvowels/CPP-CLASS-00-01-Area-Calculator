project1: main.o point.o
	g++ -o project1 main.o point.o

main.o: main.cc point.h
	g++ -c main.cc

point.o: point.cc point.h
	g++ -c point.cc
