all: a.out


main.o: main.cpp calculator.h
	g++ -c main.cpp -o main.o

calculator.o: calculator.cpp calculator.h 
	g++ -c calculator.cpp -o calculator.o

a.out: main.o calculator.o 
	g++ main.o calculator.o 
