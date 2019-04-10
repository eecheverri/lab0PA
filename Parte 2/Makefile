main: main.o A.o B.o C.o
	g++ -Wall -Werror A.o B.o C.o main.o -o main
main.o: main.cpp
	g++ -c main.cpp
A.o: A.cpp
	g++ -c A.cpp
B.o: B.cpp
	g++ -c B.cpp
C.o: C.cpp
	g++ -c C.cpp
clean:
	rm -rf main *.o
