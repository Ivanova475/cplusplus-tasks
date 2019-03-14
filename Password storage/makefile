all: a.out


main.o: main.cpp password_storage.h
	g++ -c main.cpp -o main.o

password_storag.o: password_storage.cpp password_storage.h hash_table.h
	g++ -c password_storage.cpp -o password_storage.o

hash_table.o: hash_table.cpp hash_table.h
	g++ -c hash_table.cpp -o hash_table.o

a.out: main.o password_storage.o hash_table.o
	g++ main.o password_storage.o hash_table.o
